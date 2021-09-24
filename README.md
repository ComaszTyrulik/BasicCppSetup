[![MIT License][license-shield]][license-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="#">
    <img src="docs/resources/setup.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">BasicCppSetup</h3>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
	<summary>Table of Contents</summary>
	<ol>
	    <li>
	        <a href="#about-the-project">About The Project</a>
	        <ul>
	            <li><a href="#built-with">Built With</a></li>
	        </ul>
	        <ul>
	            <li><a href="#motivation">Motivation</a></li>
	        </ul>
	        <ul>
	            <li>
	                <a href="#how-it-works">How It Works</a>
	                <ul>
	                    <li><a href="#scripts_config.yaml">scripts_config.yaml</a></li>
	                    <li><a href="#config.yaml">config.yaml</a></li>
	                </ul>
	            </li>
	        </ul>
	        <ul>
	            <li><a href="#contents">Contents</a></li>
	        </ul>
	        <ul>
	            <li><a href="#supported-platforms">Supported Platforms</a></li>
	        </ul>
	    </li>
	    <li>
	        <a href="#getting-started">Getting Started</a>
	        <ul>
	            <li><a href="#prerequisites">Prerequisites</a></li>
	        </ul>
	    </li>
	    <li><a href="#usage">Usage</a></li>
	    <li><a href="#license">License</a></li>
	    <li><a href="#acknowledgements">Acknowledgements</a></li>
	</ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This repository contains a basic template for new projects with `C++17`, `CMake` and `Conan`.

### Motivation
I had to deal with a lot of boilerplate when creating new C++ projects, and wanted to have all of it predefined. Moreover, I needed a way to easily manage project files in `CMake` and `Visual Studio`. I struggled a lot with Visual Studio's CMake support and couldn't get to work adding new files under right directories and updating files lists in `CMakeLists.txt` files at the same time.
So, I created a bunch of scripts which allow to quickly add/move/delete files from correct directories while keeping in synch both IDE's and CMake's files lists.


### How it works
Project is split in two parts - CMake and Scripts.
CMake part consists of all the `CMakeLists.txt` files, targets definitions, etc. Basically, the same stuff you would normally do for a CMake project.

The center part of the scripts part are two files. The `scripts/config/scripts_config.yaml` and the `config/config.yaml` file. As their names imply, they contain scripts configuration.

### scripts_config.yaml
This file contains absolute paths to the important files and directories for the scripts.
The file itself and all its content are defined when [initializing the project](#installation). This means, this file is not included in the repository and stores information related to the machine the scripts operate on.

The `scripts_config.yaml` file is based on the `scripts_config.yaml.dist` which is included in the repository and has the following structure:

```yaml
build_dir_path:
config_path:
project_path:
```

 - `build_dir_path` - this is the absolute path to CMake build directory
 - `config_path` - absolute path to the `config.yaml` file. Note, that by default, this file is stored under the `*repository_main_dir*/config/config.yaml` path, but it can be placed in different place too
 - `project_path` - absolute path to the main directory of the repository. Eg. if you clone this repository into the `C:/Projects/BasicCppSetup`, you must set this variable to `C:/Projects/BasicCppSetup`. This is very important, because all [commands](#usage) will be executed relative to this path


### config.yaml
This file contains the configuration of the project.

Here's the example of this file:

```yaml
conan:
  file_path: conan/conanfile.py
  build_dir: conan/build
targets:
  lib:
    tests: false
    namespace: cps
    headers:
      base_dir: include/Lib
      cmake_variable_file: src/Lib/CMakeLists.txt
      cmake_variable_name: LIB_HEADERS_LIST
    sources:
      base_dir: src/Lib
      cmake_variable_file: src/Lib/CMakeLists.txt
      cmake_variable_name: LIB_SRC_LIST
```

 - `conan` - it contains all conan-related definitions
	 + `file_path` - defines path to the `conanfile.py` file
	 + `build_dir` - path to the directory where all local, conan releated files will be placed
 - `targets` - this is the most important element of the file. It contains a list of all CMake targets whose files can be modified by the scripts. For each target you have to define the following:
	 + `tests` - tell scripts if the target contains tests. This flag is used when creating new classes. If true, new file will be created from the [`test_template`](scripts/config/test_template.h) and if false, new file will be created from the [`class_template`](scripts/config/class_template.h)
	 + `namespace` - new classes and interfaces will be created within this namespace, unless you explicitly state otherwise when creating new files from a terminal. (See [commands](#usage))
	 + `headers`
		 * `base_dir` - base directory of all `*.h` files of this target
		 * `cmake_variable_file` - when adding/moving/deleting files, scripts must modify the list of header files, the CMake target will build. This field defines where to search for that list
		 * `cmake_variable_name` - this defines the name of the variable which stores the aforementioned list. Scripts will be looking for `set({cmake_varialbe_name} *list of files*)` variable inside the `cmake_variable_file`.
	 + `sources` - it contains exactly the same fields as the `headers` field. The only difference is that these values reference `base_dir`, `cmake_variable_file` and `cmake_variable_name` for the source (`*.cpp`) files of the target

Note that all paths defined in this file are relative. That's because the `config.yaml` file is part of the repository and shouldn't contain any local specific information. All of the paths are created based on the project's absolute path defined in the `scripts_config.yaml` file.

For example, the full path to the base directory of a target's source files is created like this:
```
scriptsConfig['project_path']/targetConfig['sources']['base_dir']
```

### Contents
`BasicCppSetup` consists of the following elements:

 - Directories structure
 - Base `CMakeLists.txt`
 - Single `exe` target
 - Single `static lib` target
 - Single unit and integration tests targets for `Lib` target
 - [CommonUtilities](https://github.com/ComaszTyrulik/CommonUtilities) as submodule
 - [conanfile](https://docs.conan.io/en/latest/reference/conanfile.html)
 - Project management scripts
 - Extended `.gitignore`
 - [Doxyfile](https://www.doxygen.nl/manual/starting.html) file
 - [.clang-format](https://clang.llvm.org/docs/ClangFormat.html) file

### Directories Structure
This repository comes with the predefined directories structure for your C++ project.
They are used as follows:

 - `cmake/` - contains targets and general config files, and `functions.cmake` file, which contains definitions for custom functions
 - `conan/` - contains `conanfile.py` and automatically created `build` directory where all additional conan files are placed. In short, it contains all `conan` related data
 - `config/`
	 + `config.yaml` - This file contains project configuration used by project scripts. More about it [here](#config.yaml)
 - `include/` - directory for all of the include files. Generally, it contains all of the `*.h` files
	 + `Lib/` - contains all includes of the `Lib` target
 - `scripts/` - contains all configuration scripts
 - `src/` - directory for all of the sources. Generally, it contains all of the `*.cpp` files
	 + `App/` - contains all source files of the `App` target
	 + `Lib/` - contains all source files of the `Lib` target
 - `tests/` - contains tests for targets
	 + `Lib/` - contains all tests (both unit and integration) for `Lib` target
		 * `Integration/`
		 * `Unit`
 - `vendor/` - contains all dependencies that cannot  be optained via `conan`

### CMake Project
The `BasicCppSetup` comes with the CMake project ready to use. It defines one target for executable, one target for static library and two targets for testing the library.

The main `CMakeLists.txt` configures the project and includes vendors and sources.
It also defines the startup project for `Visual Studio`.

Additionally, it defines a few options that can be set via teminal.


| Name | Default|Description|
|------|--------|-----------|
|`BUILD_TEST`|ON|Tells CMake whether test targets should be included in the project or not.|
|`BUILD_UNIT_TESTS`|ON|Tells CMake whether unit test should be built. This flag is used by the `tests/CMakeLists.txt` file to determine which test targets include in the project.|
|`BUILD_INTEGRATION_TESTS`|ON|The same as the `BUILD_UNIT_TESTS` but concerns integration tests.|
|`GROUP_FILES_SEPARATE`|OFF|(Only tested with `Visual Studio`) source and header files can be presented in two ways in the `IDE`. They can all be groupped together and placed under the `Code/` directory or split into `Sources` and `Headers` directories. By default, all files are groupped together. **NOTE:** you may have to delete the `build/CMakeCache.txt` or recreate the entire `build` directory after changing the option in order for this option to work.|

### Clang Format
`BasicCppSetup` contains `.clang-format` file which is used to enforce coding standards.
Here's an example of `BasicCppSetup` code format:

```c++
#include "LocalInclude1.h"
#include "LocalInclude2.h"

#include <OtherTargetsInclude1.h>
#include <OtherTargetsInclude2.h>

#include <spdlog/spdlog.h>
#include <fmt/format.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>

#define BIT_MASK 0xDEADBEAF

#define MULTILINE_DEF(a, b)         \
    if ((a) > 2)                    \
    {                               \
        auto temp = (b) / 2;        \
        (b) += 10;                  \
        someFunctionCall((a), (b)); \
    }

namespace LevelOneNamespace::LevelTwoNamespace
{
    class ITestInterface
    {
    public:
        virtual ~ITestInterface() = default;

        /**
         * Description of virtual method.
         */
        virtual void VirtualMetod1() = 0;

        /**
         * Description of virtual method with params.
         * 
         * @param value - describes value
         * @param otherValue - describes other value
         * @return some value
         */
        virtual int VirtualMethod2(int value, const char* otherValue) const = 0;
    };

    class TestBase
    {
    public:
        void PublicMethod1();
        void PublicMethod2() const;

    protected:
        void ProtectedMethod();
        void ProtectedConstMethod() const;

    private:
        void PrivateMethod();
        void PrivateConstMethod();

    protected:
        int m_protectedMember = 0;

    private:
        int m_privateMember = 1;
    };

    class TestChildClass final : public TestBase, public ITestInterface
    {
    public:
        TestChildClass(std::string value)
            : m_value(value)
        {
        }

        ~TestChildClass() = default;

        TestChildClass(const TestChildClass&) = default;
        TestChildClass(TestChildClass&&) = default;
        TestChildClass& operator=(const TestChildClass&) noexcept = default;
        TestChildClass& operator=(TestChildClass&&) noexcept = default;

        void VirtualMetod1() override;
        int VirtualMethod2(int value, const char* otherValue) const override;

    private:
        std::string m_value;
    };

    template<typename T, int size>
    bool IsSorted(T (&array)[size])
    {
        return std::adjacent_find(array, array + size, std::greater<T>()) == array + size;
    }

    std::vector<uint32_t> returnVector(
        uint32_t* longNameForParameter1,
        double* longNameForParameter2,
        const float& longNameForParameter3,
        const std::map<std::string, int32_t>& longNameForParameter4)
    {
        // TODO: This is a long comment that allows you to understand how long
        // comments will be trimmed. Here should be deep thought but it's just not
        // right time for this
        for (auto& i : longNameForParameter4)
        {
            auto b = SomeFunctionCall(static_cast<int16_t>(*longNameForParameter2), reinterpret_cast<float*>(longNameForParameter2));
            i.second++;
        }

        do
        {
            if (a)
            {
                a--;
            }
            else
            {
                a++;
            }
        } while (false);

        return {};
    }
} // namespace LevelOneNamespace::LevelTwoNamespace

int main(int argc, char** argv)
{
    static constexpr unsigned int SOME_VALUE = 9;
    static constexpr int REVERSE_VALUE_MIN = 2;
    static constexpr int REVERSE_VALUE_MAX = 9;

    std::srand(std::time(0));

    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do
    {
        std::random_shuffle(list, list + SOME_VALUE);
    } while (is_sorted(list));

    int score = 0;

    do
    {
        std::cout << "Current list: ";
        std::copy(list, list + SOME_VALUE, std::ostream_iterator<int>(std::cout, " "));

        int reverseCount;
        while (true)
        {
            std::cout << "\nDigits to reverse? ";
            std::cin >> reverseCount;
            if (reverseCount < REVERSE_VALUE_MIN || reverseCount > REVERSE_VALUE_MAX)
            {
                spdlog::error("Please enter a value between {} and {}.", REVERSE_VALUE_MIN, REVERSE_VALUE_MAX);
                continue;
            }

            break;
        }

        ++score;
        std::reverse(list, list + reverseCount);
    } while (!IsSorted(list));

    const auto message = fmt::format("Congratulations, you sorted the list.\nYou needed {} reversals.\n", score);
    std::cout << message;

    return 0;
}
```
Note that you can modify the `.clang-format` file to your needs using [this](https://clang.llvm.org/docs/ClangFormatStyleOptions.html) reference.

### Supported Platforms
Currently, the project has only been built and tested on:

 - Windows 10

<!-- GETTING STARTED -->
## Getting Started
This section contains all required information to get you up and running.

### Prerequisites
Project scripts use Python virtual environment and install all dependencies there. Because of this, the only required thing to install is [Python](https://www.python.org/downloads/). The minimum required version is `3.8`. When installing python, make sure to add it to your `PATH`.

To make sure python is added to `PATH`, open your favorite terminal and type

```shell
python --version
```

### Installation
Once you have installed all prerequisites, you are good to go with project installation.

 > NOTE: This repository is meant to be used as a template, so we'll assume that you have created a new repository called `MyProject` based on this template, and that you are executing all the commands for your repository.

**Windows**

1. Clone the repository
	
	```
	git clone https://github.com/MyAccount/MyProject.git
	```
2. Cd into project folder

	```
	cd MyProject
	```
3. Run installation scripts:
	
	```
	init.bat
	```  
This will download submodules, install python's virtual environment, install required `Conan` dependencies and configure `CMake` project. This is also the step where you can pass all `CMake` options you would like to set, for example `-DBUILD_TESTS=OFF`. They will be automatically forwarded to `CMake`.

The command will ask you for the project base directory, project's config directory and project's build directory. If you run the command from your project's base directory, you can leave the aforementioned options empty and correct default ones will be used.

> NOTE: You you run the script from explorer and not from the terminal, make sure to NOT close the `cmd` window and wait for the script to finish executing. The `cmd` window should close automatically once the script is done.
  
This comman will also create the `run.bat` file in your project's base directory. You can use it to [run development scripts](#usage).

## Usage
After [initializing the project](#installation), you should have the `run.*` (the extension depends on the platform you're on. I will assume `Windows` in the following section).

This script is an entry point for all project related commands. To see the list of available commands, run:

```
run.bat -h
```

Here's the snapshot of the currently available commands:

```
usage: run <command> [<args>][-h|--help]

This program let's you manage project's config and targets
as well as running cmake and conan functions.

Available commands
 target     Performs operations on targets
 config     Performs operations on config
 conan      Installs project dependency using conan
 cmake      Runs CMake configuration command

positional arguments:
  <command>   command to execute

optional arguments:
  -h, --help  show this help message and exit
```

### Target Command
The `target` command is used to manage `CMake` targets' data. It's main purpose is to modify target's header and source files.

```
usage: run target <target> <command> [<args>][-h|--help]

Performs operations on selected target's files.

Available commands
 header     Add/Remove/Move header files
 source     Add/Remove/Move source files
 class      Add/Remove/Move header and source files at the same time

For the list of available targets, execute:  run config --targets-list

positional arguments:
  <target>    target for which the files should be added
  <command>   command to execute

optional arguments:
  -h, --help  show this help message and exit
```

You can add/remove/move headers, sources and classes.

The `headers` command allows you to modify only headers. It also allows you to create new interfaces (pure virtual classes)

The `source` commans allows you to modify only sources.

The `class` command allows you to modify both headers and sources. It also uses files templates defined in [here](scripts/config/) to create new classes.

> NOTE: This command accepts `<target>` as its first argument. This must be one of the targets defined in the [`config/config.yaml`](#config.yaml) file.

The example usage of this command might look like this:

```
run.bat target lib class add MyDirectory/MyClass
```

This will result in creation of the new `MyClass.h` and `MyClass.cpp` files under:

```
# Header
scriptsConfig['project_path']/targetConfig['headers']['base_dir']/MyDirectory/MyClass.h

# Source
scriptsConfig['project_path']/targetConfig['sources']['base_dir']/MyDirectory/MyClass.cpp
```

It will also modify `CMake` variables so that both `MyClass.h` and `MyClass.cpp` are included both in the `IDE` and in the build process.

> NOTE: When modifying target's files, remember to use paths relative to the target's headers/sources `base_dir` defined in the [`config/config.yaml`](#config.yaml) file.

### Config Command
The `config` command is used to perform operation on project configuration. Currently, it can only be used to retrieve the list of targets defined in the `config.yaml` file.

### Conan Command
This command install `Conan` dependencies and doesn't accept any arguments. You should use it whenever you modify the `conanfile.py` file.

### Cmake Command
The `cmake` command is used to both configure `CMake` project and to build all targets.

Command accepts one, **optional** argument which can be one of the two:

 - configure - regenerates cmake files. It's the `cmake` command you run everytime, you change something in your `CMakeLists.txt` files.
 - build - build all targets based on the configuration. This is an equvelant of running `cmake --build build`
 
If no argument is provided, the command proceeds as if the `configure` argument was passed.

Additionally, the `configure` argument can be provided with a list of `CMake` options in the form of `-D*NAME_OF_YOUR_OPTION*=*VALUE*`, eg:

```
run.bat cmake configure -DBUILD_UNIT_TESTS=OFF -DBUILD_INTEGRATION_TESTS=ON
```

## License
Distributed under the MIT License. See `LICENSE` for more information.

## Acknowledgements
* [README template](https://github.com/othneildrew/Best-README-Template)
* Icons made by [Freepik](https://www.freepik.com) from [www.flaticon.com](https://www.flaticon.com/)


[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: LICENSE
