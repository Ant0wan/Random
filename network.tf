resource "google_compute_network" "vpc_network" {
  name = "${var.info.name}-vpc"
  description = "Private network for the Kubernetes private cluster"
  routing_mode = "GLOBAL"
  mtu  = 1460
  project = var.info.id
}
