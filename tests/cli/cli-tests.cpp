#include <fstream>
#include "../src/cli/input-reader.hpp"
#include "../src/cli/cli.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../mocks/input-reader.hpp"
#include "../mocks/field.hpp"
#include "../mocks/command-tree.hpp"
#include "../mocks/command-builder.hpp"
#include "../mocks/cli-command.hpp"

using ::testing::Return;
using ::testing::_;

TEST(InputReaderTest, ShouldBuildAReader) {
    std::ifstream ifs;
    ifs.open("./cli/should-build-a-reader-test.txt", std::ifstream::in);
    InputReader reader(&ifs);
    ifs.close();
}

TEST(InputReaderTest, ShouldReadAFullLine) {
    std::ifstream ifs;
    ifs.open("./cli/should-read-a-full-line-test.txt", std::ifstream::in);
    InputReader reader(&ifs);
    std::string result = reader.readline();
    EXPECT_EQ(result, "This is indeed a long line");
    ifs.close();
}

TEST(InputReaderTest, ShouldReadAnIntegerValue) {
    std::ifstream ifs;
    ifs.open("./cli/should-read-an-integer-test.txt", std::ifstream::in);
    InputReader reader(&ifs);
    short int result = 0;
    reader.readValue(result);
    EXPECT_EQ(result, 13);
    ifs.close();
}

TEST(InputReaderTest, ShouldNotReadInvalidData) {
    std::ifstream ifs;
    ifs.open("./cli/should-not-read-invalid-data-test.txt", std::ifstream::in);
    InputReader reader(&ifs);
    short int result = 0;
    EXPECT_EQ(result, 0);
    ifs.close();
}

TEST(CliTest, ShouldBuildACli) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    MockCliCommandBuilder builder;
    MockCliCommand* mockCommand = new MockCliCommand();

    EXPECT_CALL(builder, buildCommand(_))
        .WillRepeatedly(Return(CliCommandNode { "sample", mockCommand }));

    Cli cli { &mockCommandTree, &mockField, &builder, &mockReader };
}

TEST(CliTest, ShouldRunACommandSuccessfully) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    MockCliCommandBuilder builder;
    MockCliCommand mockCommand;

    EXPECT_CALL(mockField, generate(_, _))
        .Times(1);    
    EXPECT_CALL(mockCommand, execute())
        .Times(2);
    EXPECT_CALL(builder, buildCommand(_))
        .Times(5)
        .WillOnce(Return(CliCommandNode { "sample", &mockCommand }))
        .WillRepeatedly(Return(CliCommandNode { "exit", &mockCommand }));
    EXPECT_CALL(mockReader, readline())
        .Times(2)
        .WillOnce(Return("sample"))
        .WillRepeatedly(Return("exit"));

    Cli cli { &mockCommandTree, &mockField, &builder, &mockReader };
    cli.run();
}

TEST(CliTest, ShouldNotBreakIfCommandIsUnknown) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    MockCliCommandBuilder builder;
    MockCliCommand mockCommand;

    EXPECT_CALL(mockField, generate(_, _))
        .Times(1);    
    EXPECT_CALL(mockCommand, execute())
        .Times(1);
    EXPECT_CALL(builder, buildCommand(_))
        .Times(5)
        .WillOnce(Return(CliCommandNode { "sample", &mockCommand }))
        .WillRepeatedly(Return(CliCommandNode { "exit", &mockCommand }));
    EXPECT_CALL(mockReader, readline())
        .Times(2)
        .WillOnce(Return("blargh"))
        .WillRepeatedly(Return("exit"));

    Cli cli { &mockCommandTree, &mockField, &builder, &mockReader };
    cli.run();
}


TEST(CommandBuilderTest, ShouldBuildABuilder) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    CliCommandBuilder builder(
        &mockCommandTree,
        &mockField,
        &mockReader
    );
}

TEST(CommandBuilderTest, ShouldBuildPrintHelpCommand) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    CliCommandBuilder builder(
        &mockCommandTree,
        &mockField,
        &mockReader
    );

    EXPECT_CALL(mockCommandTree, toString())
        .Times(1)
        .WillRepeatedly(Return("Sample Command Tree\n"));

    CliCommandNode node = builder.buildCommand(PRINT_HELP_COMMAND);
    node.command->execute();

    EXPECT_EQ(node.key, "print help");
}

TEST(CommandBuilderTest, ShouldBuildCreateMinefieldCommand) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    CliCommandBuilder builder(
        &mockCommandTree,
        &mockField,
        &mockReader
    );

    EXPECT_CALL(mockField, generate(_, _))
        .Times(1);

    CliCommandNode node = builder.buildCommand(CREATE_MINEFIELD);
    node.command->execute();

    EXPECT_EQ(node.key, "minefield create");
}

TEST(CommandBuilderTest, ShouldBuildPrintMinefieldCommand) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    CliCommandBuilder builder(
        &mockCommandTree,
        &mockField,
        &mockReader
    );

    EXPECT_CALL(mockField, toString())
        .Times(1)
        .WillRepeatedly(Return("Sample minefield\n"));

    CliCommandNode node = builder.buildCommand(PRINT_MINEFIELD);
    node.command->execute();

    EXPECT_EQ(node.key, "minefield print");
}

TEST(CommandBuilderTest, ShouldBuildProbeMinefieldCommand) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    CliCommandBuilder builder(
        &mockCommandTree,
        &mockField,
        &mockReader
    );

    std::map<::Point, BombCount> mockProbeReturn = {
        { ::Point { 10, 20 }, 10 }
    };

    EXPECT_CALL(mockReader, readValue(_))
        .Times(2);

    EXPECT_CALL(mockField, probe(_))
        .Times(1)
        .WillRepeatedly(Return(mockProbeReturn));

    EXPECT_CALL(mockField, toString())
        .WillRepeatedly(Return("Sample minefield"));

    CliCommandNode node = builder.buildCommand(PROBE_MINEFIELD);
    node.command->execute();

    EXPECT_EQ(node.key, "probe");
}


TEST(CommandBuilderTest, ShouldBuildSweepMinefieldCommand) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    CliCommandBuilder builder(
        &mockCommandTree,
        &mockField,
        &mockReader
    );

    std::map<::Point, BombCount> mockProbeReturn = {
        { ::Point { 10, 20 }, -1 }
    };

    EXPECT_CALL(mockField, sweep())
        .Times(1)
        .WillRepeatedly(Return(mockProbeReturn));

    CliCommandNode node = builder.buildCommand(SWEEP_MINEFIELD);
    node.command->execute();

    EXPECT_EQ(node.key, "sweep");
}


TEST(CommandBuilderTest, ShouldBuildUnknownCommand) {
    MockInputReader mockReader;
    MockField mockField;
    MockCommandTree<Node<CliCommand*, StringKeySpec>> mockCommandTree;
    CliCommandBuilder builder(
        &mockCommandTree,
        &mockField,
        &mockReader
    );

    CliCommandNode node = builder.buildCommand(CommandKey(99));
    EXPECT_EQ(node.key, "unknown");
    EXPECT_EQ(node.command, nullptr);
}