#include <iostream>
#include <cstring>
#include <PDFWriter.h>
#include <PDFParser.h>
#include <InputFile.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++)
    {
        if (std::strcmp(argv[i], "-h") == 0) {
            std::cout << "usage: pdfmerge [-h] [-v] file1 file2 ... output.pdf";
            exit(0);
        }
        if (std::strcmp(argv[i], "-v") == 0)
        {
            std::cout << "1.0.0";
            exit(0);
        }
    }

    if (argc == 2) {
        std::cout << "Please input at one input file and an output file";
        exit(0);
    }

    PDFWriter writer;
    writer.StartPDF(argv[argc - 1], ePDFVersion13);
    for (int i = 1; i < argc; i++)
    {
        writer.AppendPDFPagesFromPDF(argv[i], PDFPageRange());
    }
    writer.EndPDF();
}