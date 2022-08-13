terraform {
  required_version = ">=0.13.0"
  backend "gcs" {
    bucket      = "houston-texas"
    prefix      = "terraform/state"
    credentials = ".credentials.json"
  }
}

provider "google" {
  project = var.info.id
  region  = var.info.region
}
