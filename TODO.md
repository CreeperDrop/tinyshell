# TinyShell - TODO

## Short-term goals

- [x] Implement `$PATH` lookup capabilities so you can run external commands without `/bin/`
- [x] Add support for a built-in `cd`
- [x] Handle empty input (currently causes segfault)

## Long-term goals (development hell)

- [x] Add background jobs support
- [x] Handle signals like Ctrl+C (`SIGINT`) 
- [x] Add support for exiting on Ctrl+D (`EOF`)
- [x] Add a `help` built-in command describing built-ins and usage

- [x] Add I/O redirection capabilities like (`>`, `>>`)
- [ ] Add piping support (`|`)
- [ ] Add command history
- [x] Port TinyShell to FreeBSD as a learning exercise

## Notes to self

- Stick to POSIX to stay compatible with BSD for the later port
- Simple and clear is beauty

- *Scio me nihil scire.* - I know that I know nothing

