# Explore using backtrace

Backtrace provides an array of stack addresses
and alternatively symbols of the routines called.

A critical item is that for gcc the LDFLAGS -rdynamic is required.
See [this stackoverflow question](https://stackoverflow.com/a/58204327/4812090).
