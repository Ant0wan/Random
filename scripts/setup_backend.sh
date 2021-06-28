#!/usr/bin/env bash
export GOOGLE_APPLICATION_CREDENTIALS=${PWD}/.credentials.json
export TF_VAR_backend_bucket=houston-texas
gsutil mb gs://${TF_VAR_backend_bucket}
