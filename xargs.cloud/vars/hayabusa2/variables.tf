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
    ip_nodes = string
    ip_pods  = string
  })
}

variable "cluster" {
  description = "Kubernetes configuration variables"
  type = object({
    name          = string
    node_pool     = string
    node_quantity = number
    machine       = string
  })
}

variable "project_id" {
  description = "project id"
  type        = string
}

variable "github_token" {
  description = "token for github"
  type        = string
}

variable "github_owner" {
  description = "github owner"
  type        = string
}

variable "repository_name" {
  description = "repository name"
  type        = string
}

variable "organization" {
  description = "organization"
  type        = string
}

variable "branch" {
  description = "branch"
  type        = string
  default     = "main"
}

variable "target_path" {
  type        = string
  description = "Relative path to the Git repository root where the sync manifests are committed."
}

variable "flux_namespace" {
  type        = string
  default     = "flux-system"
  description = "the flux namespace"
}

variable "cluster_name" {
  type        = string
  description = "cluster name"
}

variable "cluster_region" {
  type        = string
  description = "cluster region"
}

variable "use_private_endpoint" {
  type        = bool
  description = "Connect on the private GKE cluster endpoint"
  default     = false
}

variable "github_deploy_key_title" {
  type        = string
  description = "Name of github deploy key"
}
