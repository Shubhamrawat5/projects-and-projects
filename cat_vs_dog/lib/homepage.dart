import 'package:flutter/material.dart';
import 'dart:io';
import 'package:image_picker/image_picker.dart';
import 'package:tflite/tflite.dart';

class HomePage extends StatefulWidget {
  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  final picker = ImagePicker();
  File _image;
  bool _loading = false;
  List _output;

  pickImage() async {
    var image = await picker.getImage(
      source: ImageSource.camera,
    );
    if (image == null) {
      return null;
    }
    setState(() {
      _image = File(
        image.path,
      );
    });
    classifyImage(_image);
  }

  pickGalleryImage() async {
    var image = await picker.getImage(
      source: ImageSource.gallery,
    );
    if (image == null) {
      return null;
    }
    setState(() {
      _image = File(
        image.path,
      );
    });
    classifyImage(_image);
  }

  @override
  void initState() {
    super.initState();
    _loading = true;
    loadModel().then((value) {});
  }

  @override
  void dispose() {
    Tflite.close();
    super.dispose();
  }

  classifyImage(File image) async {
    var output = await Tflite.runModelOnImage(
      path: image.path,
      numResults: 2,
      threshold: 0.5,
      imageMean: 127.5,
      imageStd: 127.5,
    );
    setState(() {
      _loading = false;
      _output = output;
    });
  }

  loadModel() async {
    await Tflite.loadModel(
      model: 'assets/model.tflite',
      labels: 'assets/labels.txt',
    );
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        Image.asset(
          "assets/backgroundpic.jpg",
          height: MediaQuery.of(context).size.height,
          width: MediaQuery.of(context).size.width,
          fit: BoxFit.cover,
        ),
        Scaffold(
          backgroundColor: Colors.transparent,
          body: Container(
            padding: EdgeInsets.symmetric(
              horizontal: 24,
            ),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: <Widget>[
                SizedBox(
                  height: 100,
                ),
                Text(
                  'Detect Dog and Cat',
                  style: TextStyle(
                    color: Colors.deepPurpleAccent,
                    fontWeight: FontWeight.w500,
                    fontSize: 28,
                  ),
                ),
                SizedBox(
                  height: 50,
                ),
                Center(
                  child: _loading
                      ? Container(
                          width: MediaQuery.of(context).size.width - 50,
                          height: 250,
                          child: Column(
                            children: <Widget>[
                              Image.asset(
                                'assets/catdog.jpg',
                              ),
                              SizedBox(
                                height: 50,
                              ),
                            ],
                          ),
                        )
                      : Container(
                          child: Column(
                            children: <Widget>[
                              Container(
                                height: 250,
                                child: Image.file(_image),
                              ),
                              SizedBox(
                                height: 20,
                              ),
                              _output != null
                                  ? Container(
                                      padding: EdgeInsets.symmetric(
                                        vertical: 10,
                                      ),
                                      child: Text(
                                        '${_output[0]['label']}',
                                        style: TextStyle(
                                          color: Colors.teal,
                                          fontWeight: FontWeight.bold,
                                          fontSize: 25.0,
                                        ),
                                      ),
                                    )
                                  : Container(),
                            ],
                          ),
                        ),
                ),
                Container(
                  width: MediaQuery.of(context).size.width,
                  child: Column(
                    children: <Widget>[
                      GestureDetector(
                        onTap: pickImage,
                        child: Container(
                          width: MediaQuery.of(context).size.width - 260,
                          alignment: Alignment.center,
                          padding: EdgeInsets.symmetric(
                            horizontal: 24,
                            vertical: 17,
                          ),
                          decoration: BoxDecoration(
                            color: Colors.deepPurple.shade300,
                            borderRadius: BorderRadius.circular(6),
                          ),
                          child: Text(
                            'Capture Photo',
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 15,
                            ),
                          ),
                        ),
                      ),
                      SizedBox(
                        height: 10,
                      ),
                      GestureDetector(
                        onTap: pickGalleryImage,
                        child: Container(
                          width: MediaQuery.of(context).size.width - 260,
                          alignment: Alignment.center,
                          padding: EdgeInsets.symmetric(
                            horizontal: 24,
                            vertical: 17,
                          ),
                          decoration: BoxDecoration(
                            color: Colors.green,
                            borderRadius: BorderRadius.circular(6),
                          ),
                          child: Text(
                            'Camera Roll',
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 15,
                            ),
                          ),
                        ),
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ),
        ),
      ],
    );
  }
}
