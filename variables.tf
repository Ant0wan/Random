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
