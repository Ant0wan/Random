<!-- TITLE -->
<br />
<div align="center">
  <img src="logo.png" alt="Logo" width="80" height="80">
  <h1 align="center">xargs.cloud</h3>
  <p align="center">
	A fully functionnal stack ready for development and production.
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#Clusters">GKE Clusters</a>
      <ul>
        <li><a href="#dev.xargs.cloud">dev.xargs.cloud</a></li>
        <li><a href="#stage.xargs.cloud">stage.xargs.cloud</a></li>
        <li><a href="#prod.xargs.cloud">prod.xargs.cloud</a></li>
      </ul>
    </li>
    <li>
      <a href="#Repository">Repository</a>
      <ul>
        <li><a href="#gitlab">Gitlab</a></li>
        <li><a href="#ci">Gitlab CI</a></li>
      </ul>
    </li>
    <li><a href="#flux">Flux CD</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>


---
ToDo:

Cloud Identity, IAM, predifined groups and associated roles: dev, devops, lead...



### GKE Clusters


Objectives: GCP Associate, small project but production grade

Dev: *James-Webb*, Guiana Space Center, Cnes

Stage: *Hayabusa II*, Usuda Deep Space, Jaxa

Prod: *New Horizons*, Deep Space Network, Nasa


#### Bootstrap with Terraform

- kubernetes cluster: kubernetes.xargs.cloud <= gives control plane

> 1. Google Networks https://cloud.google.com/training/networking-security#network-engineer-learning-path-
> 2. GKE clusters
> 3. GitHub Runners
> 4. Flux
> 5. Istio
> 6. Grafana + Prometheus

#### Tools

https://metacpan.org/dist/App-Asciio/view/lib/App/Asciio.pm

also github.com/Ant0wan/config is needed
