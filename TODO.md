# TinyShell - TODO

## Short-term goals

- [ ] Implement `$PATH` lookup capabilities so you can run external commands without `/bin/`
- [ ] Add support for a built-in `cd`
- [ ] Add better error messages for failed commands or execution calls 
- [ ] Add information messages for development purposes
- [x] Handle empty input (currently causes segfault)

## Long-term goals (development hell)

- [ ] Add background jobs support
- [ ] Handle signals like Ctrl+C (`SIGINT`) 
- [ ] Add support for exiting on Ctrl+D (`EOF`)
- [ ] Add a `help` built-in command describing built-ins and usage

- [ ] Add I/O redirection capabilities like (`<`, `>`, `>>`)
- [ ] Add piping support (`|`)
- [ ] Add command history
- [ ] Port TinyShell to FreeBSD as a learning exercise

## Notes to self

- Stick to POSIX to stay compatible with BSD for the later port
- Simple and clear is beauty

- *Scio me nihil scire.* - I know that I know nothing

