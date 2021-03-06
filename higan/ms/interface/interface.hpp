#if defined(CORE_MS)

namespace higan::MasterSystem {

extern Interface* interface;

struct AbstractInterface : Interface {
  auto root() -> Node::Object override;
  auto load(string tree = {}) -> void override;
  auto power() -> void override;
  auto run() -> void override;
  auto save() -> void override;
  auto unload() -> void override;

  auto serialize() -> serializer override;
  auto unserialize(serializer&) -> bool override;

  auto cheats(const vector<string>& list) -> void override;
};

struct MasterSystemInterface : AbstractInterface {
  auto name() -> string override { return "Master System"; }
};

struct GameGearInterface : AbstractInterface {
  auto name() -> string override { return "Game Gear"; }
};

}

#endif
