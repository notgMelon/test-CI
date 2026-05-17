# test-CI

本仓库用于熟悉和测试 C++ 项目的持续集成（CI）流程。它提供一个最小化的测试环境和示例配置，帮助开发者验证 CI 管道中的构建、单元测试和静态检查等步骤是否按预期工作。

## 仓库目的

- 提供一个轻量级的 C++ 项目示例，用于在 CI 平台（例如 GitHub Actions、GitLab CI、Travis CI 等）上验证构建与测试流程。
- 演示常见的 CI 步骤：依赖安装、构建（CMake + Make）、运行测试、生成代码覆盖率或静态分析报告。

## CI 流程示例（概览）

一个典型的 CI 流程可能包含以下阶段：

1. 检出代码（checkout）
2. 安装构建依赖（例如：gcc/clang、cmake、make）
3. 配置构建（cmake）
4. 编译（make / ninja）
5. 运行测试（ctest 或可执行测试二进制）
6. 可选：生成并上传覆盖率、静态分析或构件工件

在 GitHub Actions 中，你可以将上面步骤写入 `.github/workflows/ci.yml`，并在每次 push 或 pull request 时触发。

## 在本地构建与运行

以下命令假设你在 Linux 环境并已安装 `cmake`、`make`、`gcc` 或 `clang`。在仓库根目录运行：

```bash
# 创建构建目录并进入
mkdir -p build && cd build

# 配置（使用 Release 或 Debug）
cmake .. -DCMAKE_BUILD_TYPE=Release

# 构建
make -j$(nproc)

# 运行测试（如果项目启用了测试）
ctest --output-on-failure
```

如果项目没有启用 `ctest`，请查看 `test/` 或 `bin/` 目录中的可执行文件，并直接运行它们以确认行为。

## 常见命令模板（CI-friendly）

- 单步构建并测试：

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j2
ctest --output-on-failure
```

- 生成调试构建并跑特定测试目标：

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j$(nproc) my_test_target
./test/my_test_target
```

## 故障排查

- CMake 找不到编译器：请确保 `gcc`/`g++` 或 `clang` 已安装且在 PATH 中。
- 链接错误或缺少库：检查 `CMakeLists.txt` 中是否正确指定了库路径，或在 CI 镜像中安装相应的系统依赖。
- 测试超时或挂起：在 CI 中为测试设置合理的超时，或使用更小规模的并发。

## 建议的 CI 增强项（可选）

- 在 CI 中加入静态分析（例如 clang-tidy、cppcheck）。
- 添加代码覆盖率收集（gcov/lcov 或 llvm-cov），并可将报告上传到服务（例如 Codecov）。
- 在不同的编译器/平台上并行运行矩阵测试（如 gcc/clang，Ubuntu/macOS）。

## 联系与贡献

如果你在配置 CI 或运行构建时遇到问题，请在仓库中打开 issue 或提交 PR。欢迎贡献更完善的 CI 脚本、文档或测试用例。

--

本 README 为测试用示例，旨在帮助快速上手 CI 配置；具体项目可能需要根据依赖和构建系统进行适配。

