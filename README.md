No problem! I've updated the README to include information about adding song names to the `songs.txt` file for displaying them while playing.

---

# Music Player Project

## Overview

This project is a console-based music player implemented in C++. It allows users to manage playlists, play songs, and control playback options.

## Features

- **Playlists:** Organize your music into playlists.
- **Playback Control:** Play, pause, skip, go back, and stop songs.
- **Random Play:** Shuffle and play songs randomly.
- **Simple Console Interface:** Easy-to-use console-based user interface.

## File Structure

- **Node.h:** Defines the `node` class for the linked list nodes.
- **DoublyList.h:** Defines the abstract class `DoublyList` representing a doubly linked list.
- **MyDoublyList.h and MyDoublyList.cpp:** Implements a concrete doubly linked list class.
- **main.cpp:** The main program file implementing the music player logic.
- **songs.txt:** Text file containing a list of songs and their names for display.

## Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/farukh-javed/Music-Player.git
   ```

2. **Compile the Code:**
   ```bash
   g++ main.cpp MyDoublyList.cpp -o music_player
   ```

3. **Add Songs:**
   - Copy your audio files (in .wav format) to the project folder for playback.
   - Add the names of the songs, one per line, to `songs.txt` for display during playback.

4. **Run the Program:**
   ```bash
   ./music_player
   ```

5. **Follow on-screen instructions to use the music player.**

## Usage

- Upon starting, the program reads the list of songs and their names from `songs.txt` and creates a playlist.
- Use the menu options to control playback, navigate through playlists, and exit the program.

## Dependencies

- C++ compiler (e.g., g++)

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## License

This project is licensed under the [MIT License](LICENSE).