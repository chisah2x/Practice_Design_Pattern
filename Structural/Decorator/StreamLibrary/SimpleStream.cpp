#include <iostream>

#include "BufferedInputStream.h"
#include "BufferedOutputStream.h"
#include "FileInputStream.h"
#include "FileOutputStream.h"

void Read() {
	FileInputStream input{"test.txt"} ;
	//BufferedInputStream input{"test.txt"} ;
	std::string text{};
	while (input.Read(text)) {
		std::cout << text << std::endl;
	}
}

void Write() {
	FileOutputStream output{"test.txt"} ;
	//BufferedOutputStream output{ "test.txt" };
	output.Write("First line\n") ;
	output.Write("Second line\n") ;
	output.Write("Third line\n") ;
}

//void Encrypt() {
//	EncryptedStream output{ "test.txt" };
//	output.Write("First line");
//	output.Write("Second line");
//	output.Write("Third line");
//}
//void Decrypt() {
//	DecryptedStream input{ "test.txt" };
//	std::string text{};
//	while (input.Read(text)) {
//		std::cout << text << std::endl;
//	}
//}

//void Compress() {
//	CompressedOutputStream output{ "test.txt"  };
//	output.Write("First line");
//	output.Write("Second line");
//	output.Write("Third line");
//}
//void Decompress() {
//	DecompressedInputStream input{ "test.txt"  };
//	std::string text{};
//	while (input.Read(text)) {
//		std::cout << text << std::endl;
//	}
//}

//int main() {
//	Write();
//	Read();
//}
//
// 
// 
//int main()
//{
//	Encrypt();
//	Decrypt();
//	Compress();
//	Decompress();
//}