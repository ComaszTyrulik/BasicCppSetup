[![MIT License][license-shield]][license-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="#">
    <img src="https://github.com/PerfectLoop-GS/ScrapChild-StoryEditor/blob/develop/resources/images/robot.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Scrap Child - StoryEditor</h3>
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
		</li>
		<li>
			<a href="#supported-platforms">Supported Platforms
		</li>
		<li>
			<a href="#getting-started">Getting Started</a>
			<ul>
				<li><a href="#prerequisites">Prerequisites</a></li>
				<li><a href="#additional-useful-software">Additional Useful Software</a></li>
				<li><a href="#installation">Installation</a></li>
			</ul>
		</li>
		<li><a href="#usage">Usage</a></li>
		<li><a href="#roadmap">Roadmap</a></li>
		<li>
			<a href="#contributing">Contributing</a>
			<ul>
				<li><a href="#coding-standards">Coding Standards</a></li>
			</ul>
		</li>
		<li><a href="#license">License</a></li>
		<li><a href="#acknowledgements">Acknowledgements</a></li>
	</ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This repository contains the *StoryEditor* which is a program used to create and edit stories for the [Scrap Child game]().

### Built With
* [C++17](https://en.cppreference.com/w/cpp/17)
* [Dear ImGui](https://github.com/ocornut/imgui)

### Supported Platforms
Currently the Editor supports

 - Windows 7+

<!-- GETTING STARTED -->
## Getting Started

This section contains all required information to get you up and running on the Editor's development.

### Prerequisites

#### [CMake](https://cmake.org/)
StoryEditor uses CMake to configure and build the project's source files.
You can download CMake source files or/and binaries from [here](https://cmake.org/download/).
Minimum required version is `3.16`.

If you're going to build the project from terminal, make sure to add CMake to your `PATH`

#### [Python](https://www.python.org/downloads/)
StoryEditor uses [project scripts](https://github.com/PerfectLoop-GS/ScrapChild-Editor-Scripts) written in python. They allow easy files and classes creation. `Python 3.8` is a minimum required version.
Make sure to add Python to your `PATH`.

#### [Conan](https://conan.io/)
StoryEditor uses Conan to manage C++ dependcies.

You can install Conan by running (prefered):

```python
pip install conan
```

You can also install it via one of the download links provided [here](https://conan.io/downloads.html).

Make sure to add Conan to your `PATH`.

#### C++ 17 Compatible Compiler
StoryEditor requires `C++ 17` enabled in order to compile all of the source code. Make sure to install the compiler with C++ 17 support.

If you're using [Visual Studio 2019](https://visualstudio.microsoft.com/pl/vs/community/) you most likely already have a valid compiler.

#### [Git](https://git-scm.com/)
You can download the latest version from [here](https://git-scm.com/downloads)

### Additional Useful Software
##### VS Extensions and Configuration
Get the [Doxygen Comments extension](https://marketplace.visualstudio.com/items?itemName=FinnGegenmantel.doxygenComments) to easly create doxygen comments for classes, methods and functions.

Install [Google Test Adapter extension](https://marketplace.visualstudio.com/items?itemName=ChristianSoltenborn.GoogleTestAdapter) or install built-in Google Test Adapter provided with Visual Studio installation (make sure to check the Google Test Adapter option during Visual Studio installation).

In Visual Studio, go to `Tools > Options > Text Editor > C/C++ > Code Style > Formatting > General` (You can also search for the `clang` option in the options search bar) and check the `Enable ClangFormat support` option as well as the `Run ClangFormat for all formatting scenarios` option. This will tell Visual Studio to automatically format the code according to the provided `.clang-format` file. You can also manually trigger the code formating by pressing the `Ctrl + K + D`.

### Installation
The following contains a list of steps required to properly install the project.

##### Windows

1. Clone the repository
	
	```
	git clone https://github.com/PerfectLoop-GS/ScrapChild-StoryEditor.git
	```
2. Cd into project folder

	```
	cd ScrapChild-StoryEditor
	```
3. Run installation scripts:
	
	```
	init.bat
	```  
This will download submodules, install python's virtual environment, install required `Conan` dependencies and configure `CMake` project. It will ask you for the project base directory, project's config directory and project's build directory. If you run the command from your project's base directory, you can leave the aforementioned options empty and the correct default ones will be used.
  
  This will also create the `run.bat` file in your project's base directory. You can use it to run development scripts.

4. Open the `CMakeLists.txt` file with your favourite `IDE` or if you prefer using `Visual Studio's Solution`, go to `build` directory and open `ScrapChildEditor.sln`

## Usage

To be filled


## Roadmap

See the [open issues](https://trello.com/b/vIsC8fZq/scrapchildeditor) for a list of proposed features (and known issues).


## Contributing

In order to contribute to the Editor's code, you should follow the following steps

1. In your local repository, checkout to branch `develop` and download the latest changes:

	`git checkout develop && git fetch && git pull origin develop`
	
2. Create your branch. Go to the [issues board](https://trello.com/b/vIsC8fZq/scrapchildeditor), select the ticket and copy its id from the URL.  
Execute
	Feature branch:
	
	`git checkout -b fe-id-what-this-branch-contains`
	
	For bug branch:
	
	`git checkout -b bu-id-what-this-branch-contains`
	
	For hotfix branch:
	
	`git checkout -b hi-id-what-this-branch-contains`
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`). Make sure to make the commit message meaningful. It should describe its contents
4. Push branch to the repository (`git push origin fe-id-what-this-branch-contains`)
5. Checkout to `develop` and update it locally (`git checkout develop && git fetch && git pull origin develop)`
6. Go back to your branch and rebase it to `develop` (`git checkout fe-id-what-this-branch-contains` and then `git rebase develop`)
7. Fix merge conflicts if there are any
8. Push your updated branch to the repository (`git push origin fe-id-what-this-branch-contains --force-with-lease`)
9. Open a Pull Request to merge your branch into the `develop` (or other if your branch originated from different branch)

### Managing Files
You can use [python project scripts](https://github.com/PerfectLoop-GS/ScrapChild-Editor-Scripts) to add, rename and delete `C++` files, classes, interfaces and `google test` classes.
For the list of available commands, you can run:

```
run.bat -h
```  
Currently available commands are:

```
usage: <command> [<args>]

This program let's you manage project's targets' files.

Available commands
 header     Add/Remove/Rename header files
 source     Add/Remove/Rename source files
 class      Add/Remove/Rename header and source files at the same time
 config     Performs operations on config
 conan      installs project dependency using conan
 cmake      runs CMake configuration command

Type "<command> --help" for more information on a specific command

positional arguments:
  <command>   command to execute

optional arguments:
  -h, --help  show this help message and exit
```

Any of the files related commands will also automatically modify the appropriate target's `CMakeLists.txt` file and run `cmake -S . -B build` command, so that all of the changes are instantly visible inside the `IDE`.

### Coding Standards
The project uses [clang format](https://clang.llvm.org/docs/ClangFormatStyleOptions.html) for dictating code formatting. You can check out the above link for more information about clang-format's configurable options.

Here is a code example demonstrating most of the coding standards:

```C++
#include "LocalInclude1.h"
#include "LocalInclude2.h"

#include <OtherTargetsInclude1.h>
#include <OtherTargetsInclude2.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <spdlog/spdlog.h>
#include <fmt/format.h>

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
    /**
     * @brief Interface description
     */
    class ITestInterface
    {
    public:
        virtual ~ITestInterface() = default;

        /**
         * @brief Description of virtual method.
         */
        virtual void VirtualMethod1() = 0;

        /**
         * @brief Description of virtual method with params.
         * 
         * @see VirtualMethod1()
         *
         * @param value - describes value
         * @param otherValue - describes other value
         * @return some value
         */
        virtual int VirtualMethod2(int value, const char* otherValue) const = 0;
    };

    /**
     * @brief Class description
     */
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

    /**
     * @brief Class description
     */
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

        void VirtualMethod1() override;
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

Additionaly, below you can find information about things not covered by the above example.

### Cross-DLL API
In order to pass code safely between two DLLs, use C-style API which doesn't return any C++ specific objects (an exception to this rule are interfaces/pure abstract classes).
The C functions should have the following format:

```C++
// If function returns values and can fail:
EnumContainingErrorCodes FunctionName(Type1 someInParameter1, Type1 someInParameter, Type3* outParamToStoreReturnValue);
 
// If function returns values but can't fail:
void FunctionName(Type* outParamToStoreReturnValue);

// If function doesn't return values but can fail:
EnumContainingErrorCodes FunctionName(*ListOfInputParameters*);

// If funttion doesn't return values and can't fail:
void FunctionName(*ListOfIntpuParameters*);
```
Also, keep in mind that `C-Style` APIs should be marked as `extern "C"`:

`extern "C" void MyFunction();`

or, if multiple functions are placed inside the file:

```C++
extern "C"
{
    void MyFunction1();
    void MyFunction2();
}
```

### Error Handling
Use exceptions to inform about wrong behavior when following applies:

 - if the error is fatal and should stop the execution of the program (you can use exception in other cases to, but make sure to catch them in a proper place to allow program execution continuance)

`DO NOT` use exceptions if the following applies:

 - if encountered error isn't fatal.
 - in cross-dll Api functions. Use return value to indicate success/failure.

### Naming Convensions
#### In Code
As shown in the example, use the [PascalCase (Upper Camel Case)](https://en.wikipedia.org/wiki/Camel_case) for class, structs and custom types (except aliases for the standard types like `using uint = unsigned int`) names, as well as for methods and function names.

Use upper case letters separated by underscore `_` for `constexpr` variables and macros.

Use [camelCase (Lower Camel Case)](https://en.wikipedia.org/wiki/Camel_case) for variables.

**Prefixes**

Do not use prefixes for `protected` or `private` methods. Prefix private data members with `m_` prefix.

#### Files and Directories
Files and Directories should be written with [PascalCase (Upper Camel Case)](https://en.wikipedia.org/wiki/Camel_case). The exception to this rule can be a `main.cpp` file.

### Comments

#### In-code comments
Limit the use of comments to the places where you see fit. Mark uncertainty with comments. Try to use explicit variables and functions names instead of comments.

There are, however, places where comments are required:

 - Regex patterns - mark a reggex pattern with a short comment describing its purpose
 
#### Doxygen comments
Use doxygen comments `/** @brief comment goes here */` on interfaces' methods and methods' declarations. These comments should contain description of how to use the method, what the caller should be aware of, etc.

Additionally, use comments to describe interface and classes. If you find class without documentation, try to add a doc block.

DO NOT add doxygen comments to methods definitions, because these comments should provide a help for methods users.
 
### Magic Numbers
Do not use magic numbers. Instead, put them inside `constexpr` members.

```C++
// bad
if (value > 69)
{
    // Do something
}

...

// good
constexpr unsigned int MEANINGFUL_THRESHOLD_NAME = 69;
...
if (value > MEANINGFUL_THRESHOLD_NAME)
{
    // Do something

}
```

### Others
Other than that, follow the [official C++ Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) whenever possible.

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Acknowledgements
* [README template](https://github.com/othneildrew/Best-README-Template)
* Icons made by [Freepik](https://www.freepik.com) from [www.flaticon.com](https://www.flaticon.com/)


[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/PerfectLoop-GS/ScrapChild-StoryEditor/blob/master/LICENSE
