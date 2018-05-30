# ![alt text](https://secure.gravatar.com/blavatar/4560c02ab420ca3cefc52ab44e8aefc1?s=32) Huffman Encoding Program

## Compile
```bash
gcc HuffmanEncoding.c -std=c11 -o HuffmanEncoding 
```
## Execute

### Encode
To encode you can do:

```bash
./HuffmanEncoding -File "PathOfFile" 
```

Or if you want to change the names of the files:

```bash
./HuffmanEncoding -File "PathOfFile" -EncodedFile "NameOfTheEncodedFile" -KeyFile "NameOfTheKeyFile"
```
Remember, by default the names are:

* EncodedFile = `EncodedFile.mini`
* KeyFile = `Key.bin`

### Decode
To decode is as simple as add the `-Decode` flag
