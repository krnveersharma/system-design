// The facade pattern is a structural design pattern 
// used to provide a simplified, unified interface to a complex subsystem or set of components. 
// It is commonly used in C++ to reduce system complexity, minimize dependencies, 
// and increase ease of use for clients interacting with sophisticated APIs or systems.

// Key Concepts

// 1. Facade Class: Provides high-level methods to perform operations that internally coordinate calls to multiple subsystem classes.
// 2. Subsystem Classes: These are the underlying components that contain the complex logic. The client doesn't interact with them directly.
// 3. Client: Uses only the facade interface without dealing with the complexities of subsystems.


//Subsystems
#include<iostream>
using namespace std;

// Subsystem 1
class Demuxer{
public:
    bool openFile(const string& file) {
        cout << "Demuxer: Opening file: " << file << endl;
        return true;
    }
    void closeFile() {
        cout << "Demuxer: Closing file" << endl;
    }
};

// Subsystem 2
class VideoDecoder {
public:
    void decode() {
        cout << "VideoDecoder: Decoding video stream" << endl;
    }
};

// Subsystem 3
class AudioDecoder {
public:
    void decode() {
        cout << "AudioDecoder: Decoding audio stream" << endl;
    }
};


// Facade
class VideoPlayerFacade{
private:
    Demuxer demuxer;
    VideoDecoder videoDecoder;
    AudioDecoder audioDecoder;
public:
    void play(string fileName){
        if(!demuxer.openFile(fileName)) return;
        videoDecoder.decode();
        audioDecoder.decode();
        demuxer.closeFile();
    }
};

int main(){
    VideoPlayerFacade player;
    player.play("movie.mp4");
    return 0;
}