# StepMotorDrive

## OverView

ステッピングモータに励磁信号を出力するためのプログラムです。
ITU1割り込みによる実行を想定しています。

## Usage

### 開発環境

`make`コマンドを実行することで、`main.c`がビルドされます。  
生成された`a.out`を実行することでx86環境でのユニットテストが可能です。  
(実行環境は macOS Catalina 10.15.5 です。これ以外の環境でのテストは行っていません。)

### 実行環境 (H8)

このリポジトリをクローンし、`motordrive/motorDrive.h`の

    #define DEBUG

の一行をコメントアウトしてください。  
また、必要に応じて `Emluator/` 配下を削除し、以下に示すディレクトリのみプロジェクトにコピーしてください。  

 - motorDrive/
 - accTable/




