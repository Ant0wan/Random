resource "google_container_cluster" "mariner" {
  name                     = var.cluster.name
  location                 = var.info.region
  remove_default_node_pool = true
  initial_node_count       = 1
}

resource "google_container_node_pool" "mariner_nodes" {
  name       = var.cluster.node_pool
  location   = var.info.region
  cluster    = google_container_cluster.mariner.name
  node_count = var.cluster.node_quantity

  node_config {
    preemptible  = true
    machine_type = var.cluster.machine
  }
}
