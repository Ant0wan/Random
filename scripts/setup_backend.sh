#!/usr/bin/env bash
# Dev
export TF_VAR_backend_bucket=houston-texas
gsutil mb gs://${TF_VAR_backend_bucket}
export GOOGLE_APPLICATION_CREDENTIALS=${PWD}.credentials.json
