# GCP Bucket for remote backend
terraform {
  required_version = ">=0.13.0"
  backend "gcs" {
    bucket = "cnes"
    prefix = "terraform/state"
    credentials = ".credentials.json"
  }
}
