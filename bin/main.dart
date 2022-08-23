// ignore_for_file: public_member_api_docs, sort_constructors_first
import 'dart:io';
import 'dart:typed_data';

import 'package:path/path.dart' as p;

void main() async {
  var filePath = p.join(Directory.current.path, 'assets', 'data.txt');
  File file = File(filePath);

  var fileContent = await file.readAsBytes();

  Uint8List packet = fileContent.sublist(0, 68);

  bool isTruePacket = (packet[0] == 0xAA) && (packet[1] == 0xBB);

  print('isValidHeader = $isTruePacket');

  // this is checksum operation
  var checksum = packet.sublist(2, 67).reduce((a, b) => a + b);
  bool isValidChecksum = (checksum.toUnsigned(8) == packet[67]);
  print('isValidChecksum = $isValidChecksum');
  print('packet:\n$packet\n');

  //

  SensorData sensorData = SensorData.fillFromPacket(packet);
  print('time = ${sensorData.time}');
  print('imu = ${sensorData.imu}');
  print('gpsFlag = ${sensorData.gpsFlag}');
  print('pos = ${sensorData.pos}');
  print('vel = ${sensorData.vel}');
}

class SensorData {
  SensorData({
    required this.header,
    required this.time,
    required this.imu,
    required this.gpsFlag,
    required this.pos,
    required this.vel,
    required this.att,
    required this.gyroBias,
    required this.accBia,
    required this.sum,
  });

  int header; // 2 Byte
  int time; // 4 Byte
  List<int> imu; // List size 6, 4 Byte
  int gpsFlag; // 1 Byte
  List<int> pos; // List size 3, 4 Byte
  List<int> vel; // List size 3, 2 Byte
  List<int> att; // List size 3, 2 Byte
  List<int> gyroBias; // List size 3, 2 Byte
  List<int> accBia; // List size 3, 2 Byte
  int sum;
  //-----------

  factory SensorData.fillFromPacket(Uint8List packet) {
    // Int16 header;
    // Uint32 time;
    // Int32List imu; // size 6
    // Int8 gpsFlag;
    // Int32List pos; // size 3
    // Int16List vel; // size 3
    // Int16List att; // size 3
    // Int16List gyroBias; // size 3
    // Int16List accBia; // size 3
    // Uint8 sum;
    // ----------------------

    int header; // 2 Byte
    int time; // 4 Byte
    List<int> imu = []; // List size 6, 4 Byte
    int gpsFlag; // 1 Byte
    List<int> pos = []; // List size 3, 4 Byte
    List<int> vel = []; // List size 3, 2 Byte
    List<int> att = []; // List size 3, 2 Byte
    List<int> gyroBias = []; // List size 3, 2 Byte
    List<int> accBia = []; // List size 3, 2 Byte
    int sum;

    header = (packet[0] + (packet[1] << 8)).toSigned(16);
    //
    time = (packet[2] + (packet[3] << 8) + (packet[4] << 16) + (packet[5] << 24)).toUnsigned(32);
    //
    for (int i = 0; i < 6; i++) {
      int start = 6;
      int j = 4 * i + start;
      final value = packet[j] + (packet[j + 1] << 8) + (packet[j + 2] << 16) + (packet[j + 3] << 24);
      imu.add(value.toSigned(32));
    }
    //
    gpsFlag = packet[30];
    //
    for (int i = 0; i < 3; i++) {
      int start = 31;
      int j = 4 * i + start;
      final value = packet[j] + (packet[j + 1] << 8) + (packet[j + 2] << 16) + (packet[j + 3] << 24);
      pos.add(value.toSigned(32));
    }
    //
    for (int i = 0; i < 3; i++) {
      int start = 43;
      int j = 2 * i + start;
      final value = packet[j] + (packet[j + 1] << 8);
      vel.add(value.toSigned(16));
    }
    //
    for (int i = 0; i < 3; i++) {
      int start = 49;
      int j = 2 * i + start;
      final value = packet[j] + (packet[j + 1] << 8);
      att.add(value.toSigned(16));
    }
    //
    for (int i = 0; i < 3; i++) {
      int start = 55;
      int j = 2 * i + start;
      final value = packet[j] + (packet[j + 1] << 8);
      gyroBias.add(value.toSigned(16));
    }
    //
    for (int i = 0; i < 3; i++) {
      int start = 61;
      int j = 2 * i + start;
      final value = packet[j] + (packet[j + 1] << 8);
      accBia.add(value.toSigned(16));
    }
    //
    sum = packet[67].toUnsigned(8);
    // ---------------------------
    return SensorData(
      header: header,
      time: time,
      imu: imu,
      gpsFlag: gpsFlag,
      pos: pos,
      vel: vel,
      att: att,
      gyroBias: gyroBias,
      accBia: accBia,
      sum: sum,
    );
  }
}
