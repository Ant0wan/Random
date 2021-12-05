info = {
  name   = "pluton"
  id     = "pluton-317810"
  region = "europe-west1"
}

network = {
  ip_nodes = "10.2.0.0/16"
  ip_pods  = "192.168.10.0/24"
}

cluster = {
  name          = "outer-planets"
  node_pool     = "mariner-jupiter-saturn"
  node_quantity = 3
  machine       = "e2-medium"
}
