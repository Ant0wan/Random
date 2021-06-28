variable "info" {
  type = object({
    name   = string
    id     = string
    region = string
  })
  description = "Global variables related to project level"
}

variable "network" {
  description = "Network variables for the Kubernetes cluster"
  type = object({
    ip_range = string
  })
}
