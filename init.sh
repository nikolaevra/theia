#!/usr/bin/env bash

# Install Bazel https://docs.bazel.build/versions/master/install-ubuntu.html
sudo apt-get install openjdk-8-jdk
echo "deb [arch=amd64] http://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
curl https://bazel.build/bazel-release.pub.gpg | sudo apt-key add -
sudo apt-get update
sudo apt-get install bazel
sudo apt-get install --only-upgrade bazel

# If you ran the Bazel installer with the --user flag as above, the Bazel executable is installed in your
# $HOME/bin directory. It's a good idea to add this directory to your default paths, as follows:
export PATH="$PATH:$HOME/bin"

# Clone Tensorflow
mkdir tf
cd tf
git clone --recursive https://github.com/tensorflow/tensorflow

# Build Tensorflow
cd tensorflow
./configure

# Build my project
./bazel build //...:all