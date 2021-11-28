# Welcome to MRQM

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/mathemaphysics/MRQM/CI)](https://github.com/mathemaphysics/MRQM/actions?query=workflow%3ACI)
[![PyPI Release](https://img.shields.io/pypi/v/MRQM.svg)](https://pypi.org/project/MRQM)
[![Documentation Status](https://readthedocs.org/projects/MRQM/badge/)](https://MRQM.readthedocs.io/)

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=mathemaphysics_MRQM&metric=alert_status)](https://sonarcloud.io/dashboard?id=mathemaphysics_MRQM)

# Prerequisites

Building MRQM requires the following software installed:

* A C++17-compliant compiler
* CMake `>= 3.9`
* Doxygen (optional, documentation building is skipped if missing)* Python `>= 3.6` for building Python bindings

# Building MRQM

The following sequence of commands builds MRQM.
It assumes that your current working directory is the top-level directory
of the freshly cloned repository:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

The build process can be customized with the following CMake variables,
which can be set by adding `-D<var>={ON, OFF}` to the `cmake` call:

* `BUILD_TESTING`: Enable building of the test suite (default: `ON`)
* `BUILD_DOCS`: Enable building the documentation (default: `ON`)
* `BUILD_PYTHON`: Enable building the Python bindings (default: `ON`)

# Documentation

MRQM provides a Sphinx-based documentation, that can
be browsed [online at readthedocs.org](https://MRQM.readthedocs.io).
