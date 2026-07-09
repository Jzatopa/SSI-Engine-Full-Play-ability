About
=====

Matrix Cubed Fork
=================

This checkout is being used as the Java-first fork for Buck Rogers:
Matrix Cubed reconstruction work. The immediate goal is a modern,
compilable Java runtime that reads the original game data from a user
supplied directory. Do not commit or redistribute original game assets in
this repository.

The local fork branch is `matrix-cubed-fork`, based on upstream commit
`f10f96f`.

This project tries to create an engine that can play all
SSI Goldbox game series including content created by FRUA.

All games except FRUA are playable to a varying degree. All games are still
missing party handling and combat mechanics as big features.

Most information of the inner workings of these games has been retrieved from

[Goldbox Explorer](https://github.com/simeonpilgrim/goldboxexplorer)

[Curse of the Azure Bonds](https://github.com/simeonpilgrim/coab)

Building
========

Requirements:

* Maven 3
* Java Development Kit 17

Run
`mvn clean package -Dmaven.test.skip=true`
in the project directory.

Running
=======

From the project directory run the following command:
`java -jar ./target/engine-SNAPSHOT.jar [<directory> [--no-title]]`
where `<directory>` contains the game data from any of the SSI goldbox games
and the --no-title argument skips the screens before the title menu.

In the title menu use

* D to start the demo
* G to start the game

In a dungeon use

* WSAD to move
* Ctrl-S to save

Ctrl-L will load the game,
Ctrl-Q will quit anywhere.

For the local Matrix Cubed fork workflow, the helper script below builds
the engine and launches the local original game directory by default:

`./scripts/run-matrix-cubed.sh`

The first Java combat vertical slice is a console command. It loads
`MON0CHA.DAX` monster id 52 from the original Matrix Cubed directory and
prints a deterministic scaffold fight:

`./scripts/run-combat-slice.sh`

The first headless ECL combat scene harness loads original ECL 17, jumps to
Caloris event address `0x8C54`, chooses `RETURN THE INSULT`, and executes the
real `LOAD_MON`/`COMBAT` VM path:

`./scripts/run-combat-scene.sh`

The Swing combat debug launcher opens the normal Java UI directly at the
Caloris post-choice combat branch. Press Enter/Space through continue prompts:

`./scripts/run-matrix-cubed-combat-debug.sh`

The first static combat asset screen loads original `MARSCOM.DAX` and
`COMSPR.DAX` through the Java DAX/VGA decoders and displays a fixed proof
screen:

`./scripts/run-combat-static-screen.sh`
