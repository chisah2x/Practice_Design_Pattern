#include <iostream>

#include "DecryptedStream.h"
#include "EncryptedStream.h"
#include "FileOutputStream.h"
#include "FileInputStream.h"
#include "CompressedOutputStream.h"
#include "DecompressedInputStream.h"

void Read() {
	DecompressedInputStream<DecryptedStream<FileInputStream>> in{"test.txt"} ;
	std::string text{} ;
	while(in.Read(text)) {
		std::cout << text << std::endl ;
	}
}
void Write() {
	CompressedOutputStream<EncryptedStream<FileOutputStream>> out{"test.txt"} ;
	out.Write("Using mixin to implement static decorator") ;
	out.Write("Decorators are chosen at compile-time") ;
}
int main() {
	Write() ;
	Read() ;
}
