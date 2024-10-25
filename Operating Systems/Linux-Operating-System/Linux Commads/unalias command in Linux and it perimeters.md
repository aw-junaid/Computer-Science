In Linux, the `unalias` command is used to remove aliases previously defined by the user. Aliases are custom shorthand commands that allow you to create shorter or more convenient names for frequently used commands. The `unalias` command helps you to delete these custom aliases, restoring the original behavior of the commands.

The basic syntax of the `unalias` command is:

```
unalias [alias_name]
```

Here is a table outlining the parameters of the `unalias` command:

| Parameter           | Description                                       |
|---------------------|---------------------------------------------------|
| `[alias_name]`      | Optional. Specifies the name of the alias you want to remove. If not provided, the `unalias` command will display a list of currently defined aliases and prompt you to choose one to remove.|

Examples:

1. Remove the alias for `ll` (previously defined as `ls -lh --color=auto`):
```
unalias ll
```

2. Delete an alias called `cls` (previously defined as `clear`):
```
unalias cls
```

3. Remove an alias named `desktop` (previously defined as `cd ~/Desktop`):
```
unalias desktop
```

4. Delete an alias called `psa` (previously defined as `ps -aux`):
```
unalias psa
```

5. Display a list of currently defined aliases and prompt to remove one:
```
unalias
```

Sample output:
```
alias ll='ls -lh --color=auto'
alias cls='clear'
alias desktop='cd ~/Desktop'
...
```
Choose an alias to remove (e.g., enter `ll` to remove the `ll` alias).

6. Attempt to remove a non-existing alias (no error occurs if the alias does not exist):
```
unalias non_existing_alias
```

The `unalias` command is useful for managing aliases and cleaning up your shell environment by removing aliases you no longer need or want to revert to the default behavior of specific commands.
