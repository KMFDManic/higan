struct Cartridge {
  Node::Port port;
  Node::Peripheral node;

  inline auto metadata() const -> string { return information.metadata; }
  inline auto region() const -> string { return information.region; }

  //cartridge.cpp
  auto load(Node::Object, Node::Object) -> void;
  auto connect(Node::Peripheral) -> void;
  auto disconnect() -> void;

  auto save() -> void;
  auto power() -> void;

  //serialization.cpp
  auto serialize(serializer&) -> void;

//private:
  struct Information {
    string metadata;
    string region;
  } information;

  Memory::Readable<uint8> rom;
};

extern Cartridge cartridge;
