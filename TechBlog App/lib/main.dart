import 'package:flutter/material.dart';
import 'input_page.dart';

void main() => runApp(TechBlogApp());

class TechBlogApp extends StatelessWidget {
  const TechBlogApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: InputPage(),
      theme: ThemeData.dark().copyWith(
          scaffoldBackgroundColor: Color(0xFF0A0E21),
          primaryColor: Color(0xFF0A0E21)
      ),
    );
  }
}
