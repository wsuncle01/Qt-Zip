# Qt-Zip
# Readme
这个项目主要是本人无法成功在qt中安装quazip的情况下迫不得已自己手搓的将多个文件合并为一个压缩包的代码。实际上实现的时候并没有考虑压缩文件大小，因为本人项目是生成epub电子书，没有必要一定要压缩。

## 主要函数：
`
void zip::addfile(QString path,QString data);//path是你希望data在压缩文件中存放的位置，data是你需要压缩的数据（本代码中没有压缩，只是单纯将文件放在一起）
void zip::zipfile(QString OutPutPath);//OutPutPath是输出文件名
`

## 不足之处

1.本文未对数据进行压缩，只是将文件放在了一起。如果需要压缩，那么则可能需要需要改一部分代码。
    formlocalFile()中对18-21byte偏移处以及formcentralDir()中对20-23btye偏移处，即文件压缩后大小的代码需要修改。
    formlocalFile()中对8-11byte偏移处以及formcentralDir()中对10-13btye偏移处，即压缩方法标识符的代码需要修改。
    当然数据文本也要每个单独压缩，这个qt似乎有现成的库函数可以使用。

2.本人并没有完全搞清楚central directory file中外部文件属性&内部文件属性字段的真实含义，所以在生成的时候都设置为了0。

3.由于不同编码方式对于除英文外字符的二进制码不同，crc32的值也会因此而产生差异。比如utf-8中中文字符占了3-4字节，而gbk中只有2字节。本人不是很清楚这是否会对识别压缩文件的完整性产生影响。

Description below is translated by ChatGPT

This project is mainly a code I wrote myself as a last resort when I couldn't successfully install QuaZIP in Qt. It combines multiple files into a single compressed package. In reality, the implementation does not consider the size of the compressed file because the project is generating EPUB e-books, and compression is not necessary.

## Main Functions:
---------------

`void zip::addfile(QString path, QString data); // path is the location where you want to store the data in the compressed file, and data is the data you want to compress (in this code, there is no compression, just putting the files together). void zip::zipfile(QString OutPutPath); // OutPutPath is the output file name.`

## Limitations:
------------

1.  This code does not compress the data; it just puts the files together. If compression is required, some parts of the code may need to be modified. The code related to the compressed file size at the 18-21 byte offset in `formlocalFile()` and 20-23 byte offset in `formcentralDir()` needs to be changed. Similarly, the code related to the compression method identifier at the 8-11 byte offset in `formlocalFile()` and 10-13 byte offset in `formcentralDir()` needs to be modified. Additionally, each data text would need to be compressed individually, and Qt seems to have ready-to-use library functions for that purpose.
    
2.  I haven't fully understood the true meaning of the external file attributes and internal file attributes fields in the central directory file, so I set them all to 0 when generating them.
    
3.  Due to different encoding methods having different binary codes for non-English characters, the CRC32 value may also differ. For example, Chinese characters in UTF-8 occupy 3-4 bytes, while in GBK they only occupy 2 bytes. I'm not sure if this would affect the recognition of the integrity of the compressed file.
