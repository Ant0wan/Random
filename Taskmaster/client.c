#include <argp.h>
#include <arpa/inet.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#include "client.h"
#include "process.h"
#include "help.h"

const char *argp_program_version = ARGP_VERSION;
const char *argp_program_bug_address = REPORT_BUG;
static char doc[] = CLIENT_DOC;
static char args_doc[] = ARGS_DOC;

const struct argp_option options[] =
{
	{ "configuration", 'c', "FILENAME", 0, "Configuration file path (searches if not given)", 0 },
	{ "interactive", 'i', 0, 0, "Start an interactive shell after executing commands", 0 },
	{ "serverurl", 's', "URL", 0, "URL on which supervisord server is listening (default \"http://localhost:9001\")", 0 },
	{ "username", 'u', "USERNAME", 0, "Username to use for authentication with server", 0 },
	{ "password", 'p', "PASSWORD", 0, "Password to use for authentication with server", 0 },
	{ "history-file", 'r', 0, 0, "Keep a readline history (if readline is available)", 0 },
	{ 0 }
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state->input;

	switch(key)
	{
		case 'c':
			arguments->configuration = 1;
			arguments->filename = arg;
			break;
		case 'i':
			arguments->interactive = 1;
			break;
		case 's':
			arguments->serverurl = 1;
			arguments->url = arg;
			break;
		case 'u':
			arguments->username = 1;
			arguments->user = arg;
			break;
		case 'p':
			arguments->password = 1;
			arguments->passwd = arg;
			break;
		case 'r':
			arguments->history_file = 1;
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, NULL, NULL, NULL };

static void help_command(char *input)
{
	(void)input;
	fprintf(stdout, HELP);
}

int send_command_to_deamon(struct s_client *client) {
	fprintf(stdout, "input to send: %s\n", client->input);
	/*	int sock = 0;
		struct sockaddr_in serv_addr;

		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1;
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(PORT);
		if(inet_pton(AF_INET, IP, &serv_addr.sin_addr) <= 0) return -1;
		if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) return -1;
		send(sock, client->input, INPUT_MAX, 0);
		*/	return 0;
}

static char *build_prompt(char *arg)
{
	char hostname[25];
	char *username;
	char *prompt;

	username = getlogin();
	if (!username) return NULL;
	else if (gethostname(hostname, 25) || asprintf(&prompt, PROMPT, username, hostname) == -1) {
		perror(arg);
		return NULL;
	}
	return prompt;
}

int main(int argc, char **argv) {

	struct arguments arguments = {0};
	struct s_client client = {0};
	char *prompt;

	prompt = build_prompt(argv[0]);
	if (!prompt) return EXIT_FAILURE;
	else if (argp_parse(&argp, argc, argv, 0, 0, &arguments)) {
		perror(argv[0]);
		return EXIT_FAILURE;
	} do {
		if (!(client.input = readline(prompt))) {
			free(prompt);
			clear_history();
			return EXIT_FAILURE;
		} else if (!strcmp("exit", client.input)) { /* Should be remove once cmd parser done */
			free(prompt);
			free(client.input);
			clear_history();
			return EXIT_SUCCESS;
		} else if (!strcmp("help", client.input)) { /* Should be remove once cmd parser done */
			free(client.input);
			help_command(client.input);
		} else { /* Should be remove once cmd parser done */
			if (client.input[0]) {
				add_history(client.input);
				for (int retry = 1;; ++retry) {
					if (retry >= 7) {
						fprintf(stderr, "Failed to connect to deamon\n");
						break;
					} else if (send_command_to_deamon(&client)) {
						fprintf(stderr, "Attempt %d/6: send command to deamon: ", retry);
						perror(NULL);
						sleep(retry);
					} else break;
				}
			}
			free(client.input);
		}
	}
	while (1);

	free(prompt);
	clear_history();

	return EXIT_FAILURE;
}
