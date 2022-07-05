[![Build & Test](https://github.com/danielealbano/cachegrand/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/danielealbano/cachegrand/actions/workflows/build_and_test.yml)
[![codecov](https://codecov.io/gh/danielealbano/cachegrand/branch/main/graph/badge.svg?token=H4W0N0F7MT)](https://codecov.io/gh/danielealbano/cachegrand)
[![Last Commit](https://img.shields.io/github/commit-activity/m/danielealbano/cachegrand/main)](https://github.com/danielealbano/cachegrand/commits/main)
[![CodeFactor Grade](https://img.shields.io/codefactor/grade/github/danielealbano/cachegrand?label=codefactor%20code%20quality)](https://www.codefactor.io/repository/github/danielealbano/cachegrand)
[![LGTM Grade](https://img.shields.io/lgtm/grade/cpp/github/danielealbano/cachegrand?label=lgtm%20code%20quality)](https://lgtm.com/projects/g/danielealbano/cachegrand/context:cpp)
![Lines of code](https://img.shields.io/tokei/lines/github/danielealbano/cachegrand)

cachegrand
==========

cachegrand is an open-source fast, scalable and modular Key-Value store designed from the ground up to take advantage of
modern hardware, able to provide better performance when compared to similar projects but also capable to provide a
great flexibility in terms of management and developer experience.

Performances:



Benchmarked on an AMD EPYC 7502P, cachegrand is able to scale linearly if enough cpu power is left to the operating
system to process the network data

Key features:
- [Modular](https://github.com/danielealbano/cachegrand/docs/architecture/modules.md) architecture to support widely used protocols, e.g.
  [Redis](https://github.com/danielealbano/cachegrand/docs/architecture/modules/redis.md),
- [Time-series database](https://github.com/danielealbano/cachegrand/docs/architecture/timeseries-db.md) for fast data writes and retrieval with
  primitives built to handle different data types (e.g. small strings, large blobs, jsons, etc.);
- [Hashtable](https://github.com/danielealbano/cachegrand/docs/architecture/hashtable.md) GET Lock-free and Wait-free operations, SET and DELETE use
  localized spinlocks, the implementation is capable to digest 2.1 billion records per second on a 1x AMD EPYC 7502 (see
  [benches](https://github.com/danielealbano/cachegrand/docs/benchmarks/hashtable.md));
- An ad-hoc [SLAB Allocator](https://github.com/danielealbano/cachegrand/docs/architecture/slab-allocator.md) (memory allocator) capable of allocating and free memory in O(1);
- Linear vertical scalability when using the in-memory database, 2x cpus means 2x requests (see
  [benches](https://github.com/danielealbano/cachegrand/docs/benchmarks/linear-vertical-scalability.md));

Planned Key Features:
- More modules for additional platforms compatibility, e.g. [Memcache](https://github.com/danielealbano/cachegrand/docs/architecture/modules/memcache.md),
  etc., or to add support for monitoring, e.g. [Prometheus](https://github.com/danielealbano/cachegrand/docs/architecture/modules/prometheus.md),
  [DataDog](https://github.com/danielealbano/cachegrand/docs/architecture/modules/datadog.md), etc.;
- Ad ad-hoc network stack based on DPDK / Linux XDP (eXpress Data Path) and the FreeBSD network stack;
- [Built for flash memories](https://github.com/danielealbano/cachegrand/docs/architecture/timeseries-db.md#flash-memories) to be able to efficiently saturate the
  available IOPS in modern DC NVMEs and SSDs;
- [WebAssembly](https://github.com/danielealbano/cachegrand/docs/architecture/webassembly.md) to provide AOT-compiled
  [User Defined Functions](https://github.com/danielealbano/cachegrand/docs/architecture/webassembly/user-defined-functions.md),
  [event hooks](https://github.com/danielealbano/cachegrand/docs/architecture/webassembly/event-hooks.md), implement
  [modules](https://github.com/danielealbano/cachegrand/docs/architecture/webassembly.md#modules), you can use your preferred language to perform operations
  server side;
- [Replication groups](https://github.com/danielealbano/cachegrand/docs/architecture/clustering-and-replication.md#replication-groups) and
  [replica tags](https://github.com/danielealbano/cachegrand/docs/architecture/clustering-and-replication.md#replica-tags), tag data client side or use
  server side events to tag the data and determine how they will be replicated;
- [Active-Active](https://github.com/danielealbano/cachegrand/docs/architecture/clustering-and-replication.md#active-active)
  [last-write-wins](https://github.com/danielealbano/cachegrand/docs/architecture/clustering-and-replication.md#last-write-wins) data replication, it's a
  cache, write to any node of a replication group to which the replication tags are assigned, no need to think worry it;

It's possible to find more information in the [docs](https://github.com/danielealbano/cachegrand/docs/) folder.

The platform is written in C, validated via unit tests, Valgrind and integration tests, it's also built with a set of
compiler options to fortify the builds ([#85](https://github.com/danielealbano/cachegrand/issues/85)).

Currently, it runs only on Linux, on Intel or AMD cpus and requires a kernel v5.7 or newer, will be ported to other
platforms once will become more feature complete.

#### Please be aware that

cachegrand is not production ready and not feature complete, plenty of basic functionalities are being implemented,
the documentation is lacking as well as it's being re-written, please don't open issues for missing documentation.

The status of the project is tracked via GitHub using the project management board.

### Issues & contributions

Please if you find any bug, malfunction or regression feel free to open an issue or to fork the repository and submit
your PRs! If you do open an Issue for a crash, if possible please enable sentry.io in the configuration file and try to
reproduce the crash, a minidump will be automatically uploaded on sentry.io.
Also, if you have built cachegrand from the source, please attach the compiled binary to the issue as well as sentry.io
knows nothing of your own compiled binaries.

### Performances

The platform is regularly benchmarked as part of the development process to ensure that no regressions slip through,
it's possibile to find more details in the [documentation](https://github.com/danielealbano/cachegrand/docs/benchmarks.md).

### How to install

#### Distro packages

Packages are currently not available, they are planned to be created for the v0.3 milestone.

#### Build from source

Instructions on how to build cachegrand from the sources are available in the
[documentation](https://github.com/danielealbano/cachegrand/docs/build-from-source.md)

### Configuration

cachegrand comes with a default configuration but for production use please review the
[documentation](https://github.com/danielealbano/cachegrand/docs/configuration.md) to ensure an optimal deployment.

### Running cachegrand

cachegrand doesn't need to run as root but please review the configuration section to ensure that enough lockable memory
has been allowed, enough files can be opened and that the slab allocator has been enabled and enough huge pages have been provided

Before trying to start cachegrand, take a look to the
[performance tips](https://github.com/danielealbano/cachegrand/docs/performance-tips.md) available in the docs section
as they might provide a valuable help!

#### Help

```shell
$ ./cachegrand-server --help
Usage: cachegrand-server [OPTION...]

  -c, --config-file=FILE     Config file (default config file
                             /usr/local/etc/cachegrand/cachegrand.conf )
  -l, --log-level=LOG LEVEL  log level (error, warning, info, verbose, debug)
  -?, --help                 Give this help list
      --usage                Give a short usage message

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.
```

#### Start it locally

```shell
/path/to/cachegrand-server -c /path/to/cachegrand.yaml
[2022-06-05T10:26:08Z][INFO       ][program] cachegrand-server version 1907aef-dirty (built on 2022-07-05T10:26:07Z)
[2022-06-05T10:26:08Z][INFO       ][program] > Release build, compiled using GCC v10.3.0
[2022-06-05T10:26:08Z][INFO       ][program] > Hashing algorithm in use t1ha2
[2022-06-05T10:26:08Z][INFO       ][config] Loading the configuration from ../../etc/cachegrand.yaml
[2022-06-05T10:26:08Z][INFO       ][program] Ready to accept connections
```

#### Docker

```shell
docker run \
  -v /path/to/cachegrand.yaml:/etc/cachegrand/cachegrand.yaml \
  --ulimit memlock=-1:-1 \
  --ulimit nofile=262144:262144 \
  cachegrand:latest
```