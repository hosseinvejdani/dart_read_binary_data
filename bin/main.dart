import 'dart:io';
import 'dart:typed_data';
import 'package:path/path.dart' as p;

void main() async {
  var filePath = p.join(Directory.current.path, 'assets', 'data.txt');
  File file = File(filePath);

  var fileContent = await file.readAsBytes();

  Uint8List packet = fileContent.sublist(0, 68);

  // this is checksum operation
  var checksum = packet.sublist(2, 67).reduce((a, b) => a + b);
  bool isValidPacket = (checksum.toUnsigned(8) == packet[67]);
  print(isValidPacket);
  //
}
