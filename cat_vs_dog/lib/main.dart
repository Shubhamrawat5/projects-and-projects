import 'package:cat_dog_predict/splashscreen.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(
    MyApp(),
  );
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Cat vs Dog Detector',
      home: SplashScreen(),
      debugShowCheckedModeBanner: false,
    );
  }
}
