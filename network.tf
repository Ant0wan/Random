resource "google_compute_network" "vpc_network" {
  name                    = "${var.info.name}-vpc"
  auto_create_subnetworks = false
  description             = "Private network for the Kubernetes private cluster"
  routing_mode            = "GLOBAL"
  mtu                     = 1460
  project                 = var.info.id
}

resource "google_compute_subnetwork" "subnetwork1" {
  name          = "${var.info.name}-node-subnet"
  ip_cidr_range = var.network.ip_nodes
  region        = var.info.region
  network       = google_compute_network.vpc_network.id
  project       = var.info.id
  secondary_ip_range {
    range_name    = "${var.info.name}-pod-subnet"
    ip_cidr_range = var.network.ip_pods
  }
}
