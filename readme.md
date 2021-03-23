# Repast.HPC Bug Report

This repository contains a demo of a bug in the Repast.HPC framework, version
2.3.1. The repo has 2 Dockerfiles, one contains the demo using the official
version of Repast.HPC and the other a patched version of Repast.HPC, where the
bug is not present. The Docker images are stored in Github, with the following
tags:

- `ghcr.io:martinparadiso/repast.hpc-bugdemo`: The demo compiled with the
  official version of Repast.HPC.
- `ghcr.io:martinparadiso/repast.hpc-bugdemo-patched`: The demo compiled with
  the patched version of Repast.HPC.

To run the simulations simply execute:

```sh
docker run ghcr.io:martinparadiso/repast.hpc-bugdemo:latest
```

for the *bugged* version, or:

```sh
docker run ghcr.io:martinparadiso/repast.hpc-bugdemo-patched:latest
```

for the patched version. The first container should count two times the same
number.
