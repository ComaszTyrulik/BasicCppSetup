from conans import ConanFile, CMake


class ScrapChildEditor(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "spdlog/[>=1.4.2]", "gtest/[>=1.8.1]", "stduuid/1.0"
    generators = "cmake"
