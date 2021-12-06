resource "google_container_cluster" "jameswebb" {
  name                     = var.cluster.name
  location                 = var.info.region
  remove_default_node_pool = true
  initial_node_count       = 1
  project                  = var.info.id
}

resource "google_container_node_pool" "jameswebb_nodes" {
  name       = var.cluster.node_pool
  location   = var.info.region
  cluster    = google_container_cluster.jameswebb.name
  node_count = var.cluster.node_quantity
  project    = var.info.id

  node_config {
    preemptible  = true
    machine_type = var.cluster.machine
  }
}
