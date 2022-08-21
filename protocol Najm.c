// typedef struct // LoggerData_t
// {
// 	int16_t Header;

// 	uint32_t time;
// 	int32_t imu[6];
// 	// int16_t Magnet[3];
// 	int8_t GpsFlag;

// 	int32_t Pos[3];
// 	int16_t Vel[3];
// 	int16_t Att[3];
// 	// int16_t AttU[3];
// 	int16_t GyroBias[3];
// 	int16_t AccelBias[3];

// 	uint8_t sum;
// } LoggerData_t;
// #pragma pack()

// LoggerData_t najm;

// if ((packet[0] == 0xAA) && (packet[1] == 0xBB))
// {
// 	s1 = fread(&packet[32], 36, 1, file);
// 	a1 += 36;

// 	cksum = 0;
// 	for (int i = 2; i < (67); i++)
// 		cksum += packet[i];

// 	if (cksum == packet[67])
// 	{
// 		NajmCntr++;
// 		memcpy(&najm.Header, packet, 68);
// 		timeNajm = 0.000001 * (najm.time);
// 		// if (sensorType == 488 || sensorType == 480)
// 		//{
// 		//	gyx = -(*((long*)&packet[6])* 0.02 / 65536.0);//    *0.02
// 		//	gyy = -(*((long*)&packet[10]) * 0.02 / 65536.0);//    *0.02
// 		//	gyz = (*((long*)&packet[14]) * 0.02 / 65536.0);//    *0.02
// 		//	acx = -(*((long*)&packet[18]) * 0.0008 / 65536.0);//    *0.0008
// 		//	acy = -(*((long*)&packet[22]) * 0.0008 / 65536.0);//    *0.0008
// 		//	acz = (*((long*)&packet[26]) * 0.0008 / 65536.0);//    *0.0008
// 		//	//if (code == 2 || code == 3) AD_temperature = 25.0f + 0.00565f * (*(short*)(&packet[36]));
// 		//	mgx = -*((short*)&packet[30]);
// 		//	mgy = -*((short*)&packet[32]);
// 		//	mgz = *((short*)&packet[34]);
// 		// }

// 		// else if (sensorType == 490)
// 		//{
// 		//	gyx = -(*((long*)&packet[6]))* 0.005 / 65536.0;//    *0.02
// 		//	gyy = -(*((long*)&packet[10])) * 0.005 / 65536.0;//    *0.02
// 		//	gyz = (*((long*)&packet[14]))  * 0.005 / 65536.0;//    *0.02
// 		//	acx = -(*((long*)&packet[18])) * 0.0005 / 65536.0;//    *0.0008
// 		//	acy = -(*((long*)&packet[22])) * 0.0005 / 65536.0;//    *0.0008
// 		//	acz = (*((long*)&packet[26])) * 0.0005 / 65536.0;//    *0.0008
// 		//	//if (code == 2 || code == 3) AD_temperature = 25.0f + (0.01428f) * (*((short*)(&packet[36])));
// 		// }
// 		// else
// 		if (sensorType == 467)
// 		{
// 			// gyx = -(*((short*)&packet[6]))* 0.025;//    *0.02
// 			// gyy = (*((short*)&packet[10])) * 0.025;//    *0.02
// 			// gyz = (*((short*)&packet[8]))  * 0.025;//    *0.02
// 			// acx = -(*((short*)&packet[12])) * 0.00125;//    *0.0008
// 			// acy = (*((short*)&packet[16])) * 0.00125;//    *0.0008
// 			// acz = (*((short*)&packet[14])) * 0.00125;//    *0.0008
// 			gyx = -0.025 * (najm.imu[0]);	  //+Imu.IMUR[2]/65536.0);
// 			gyy = +0.025 * (najm.imu[1]);	  //+Imu.IMUR[4]/65536.0);
// 			gyz = -0.025 * (najm.imu[2]);	  //+Imu.IMUR[6]/65536.0);
// 			acx = -0.00125 * (najm.imu[3]); //+Imu.IMUR[8]/65536.0);
// 			acy = +0.00125 * (najm.imu[4]); //+Imu.IMUR[10]/65536.0);
// 			acz = -0.00125 * (najm.imu[5]); //+Imu.IMUR[12]/65536.0);

// 			// gyx = gyx * 0.5 + 0.5 * gyx0;
// 			// gyy = gyy * 0.5 + 0.5 * gyy0;
// 			// gyz = gyz * 0.5 + 0.5 * gyz0;
// 			// acx = acx * 0.5 + 0.5 * acx0;
// 			// acy = acy * 0.5 + 0.5 * acy0;
// 			// acz = acz * 0.5 + 0.5 * acz0;
// 			// if (code == 2 || code == 3) AD_temperature = (*((short*)&packet[18])) * 0.1;
// 		}
// 		else if (sensorType == 70)
// 		{
// 			gyx = 0.00001 * (najm.imu[0]);
// 			gyy = 0.00001 * (najm.imu[1]);
// 			gyz = 0.00001 * (najm.imu[2]);
// 			acx = 0.00001 * (najm.imu[3]);
// 			acy = 0.00001 * (najm.imu[4]);
// 			acz = 0.00001 * (najm.imu[5]);
// 		}
// 		/*		float mgx = najm.Magnet[0]/100.0;
// 				float mgy = najm.Magnet[1]/100.0;
// 				float mgz = najm.Magnet[2]/100.0;*/

// 		fprintf(fileIMU, "\r\n%10.6f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f", timeNajm, gyx, gyy, gyz, acx, acy, acz); //, mgx, mgy, mgz  Wb(0, 0), Wb(1, 0), Wb(2, 0), Ab(0, 0), Ab(1, 0), Ab(2, 0));

// 		if (najm.GpsFlag == 1)
// 		{
// 			najm.GpsFlag = 0;
// 			double latG = 0.0000001 * najm.Pos[0];
// 			double lngG = 0.0000001 * najm.Pos[1];
// 			double altG = 0.001 * najm.Pos[2];
// 			float VnG = 0.01 * najm.Vel[0];
// 			float VeG = 0.01 * najm.Vel[1];
// 			float VdG = 0.01 * najm.Vel[2];
// 			fprintf(fileGPS, "\r\n%10.6f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f", timeNajm, latG, lngG, altG, VnG, VeG, VdG);
// 			FusionInput.groundSpeed = sqrt(VnG * VnG + VeG * VeG);

// 			FusionInput.GPSParseTime = GPS_PARS_TIME; // time_gps/1000.0;   //(time_gps-time_imu)/1000.0;
// 			FusionInput.gps_got = 1;
// 			FusionInput.lng = lngG * TO_RADIAN;
// 			FusionInput.lat = latG * TO_RADIAN;
// 			FusionInput.alt = altG;
// 			FusionInput.Vn = VnG;
// 			FusionInput.Ve = VeG;
// 			FusionInput.Vd = VdG;
// 		}
// 		else
// 		{
// 			double latF = 0.0000001 * najm.Pos[0];
// 			double lngF = 0.0000001 * najm.Pos[1];
// 			double altF = 0.001 * najm.Pos[2];
// 			float VnF = 0.01 * najm.Vel[0];
// 			float VeF = 0.01 * najm.Vel[1];
// 			float VdF = 0.01 * najm.Vel[2];
// 			fprintf(filePosF, "\r\n%10.6f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f", timeNajm, latF, lngF, altF, VnF, VeF, VdF);
// 		}
// 		float rolF = 0.01 * najm.Att[0];
// 		float pchF = 0.01 * najm.Att[1];
// 		float yawF = 0.01 * najm.Att[2];
// 		// float rolUF = 0.01 * najm.AttU[0];
// 		// float pchUF = 0.01 * najm.AttU[1];
// 		// float yawUF = 0.01 * najm.AttU[2];
// 		float bgxF = 0.0001 * najm.GyroBias[0];
// 		float bgyF = 0.0001 * najm.GyroBias[1];
// 		float bgzF = 0.0001 * najm.GyroBias[2];
// 		float baxF = 0.00001 * najm.AccelBias[0];
// 		float bayF = 0.00001 * najm.AccelBias[1];
// 		float bazF = 0.00001 * najm.AccelBias[2];
// 		fprintf(fileNajm, "\r\n%10.6f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f  %+.7f", timeNajm, rolF, pchF, yawF, bgxF, bgyF, bgzF, baxF, bayF, bazF); // rolUF, pchUF, yawUF,
