//Famicom Disk System

#include "drive.hpp"
#include "timer.hpp"
#include "audio.hpp"

struct FDS {
  Node::Port port;
  Node::Peripheral node;
  Node::String state;
  uint1 present;

  struct Disk {
    Memory::Writable<uint8> sideA;
    Memory::Writable<uint8> sideB;
  };
  Disk disk1;
  Disk disk2;
  maybe<Memory::Writable<uint8>&> inserting;
  maybe<Memory::Writable<uint8>&> inserted;
  uint1 changed;

  //fds.cpp
  auto load(Node::Object, Node::Object) -> void;
  auto unload() -> void;
  auto connect(Node::Peripheral) -> void;
  auto disconnect() -> void;
  auto change(string value) -> void;
  auto change() -> void;

  auto poll() -> void;
  auto main() -> void;
  auto power() -> void;

  auto read(uint16 address, uint8 data) -> uint8;
  auto write(uint16 address, uint8 data) -> void;

  //serialization.cpp
  auto serialize(serializer&) -> void;

private:
  struct Information {
    string metadata;
  } information;

  FDSDrive drive;
  FDSTimer timer;
  FDSAudio audio;
};

extern FDS fds;
