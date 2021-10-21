import 'package:flutter/material.dart';
import 'tech_news.dart';
import 'scholarships.dart';

class InputPage extends StatefulWidget {
  const InputPage({Key? key}) : super(key: key);

  @override
  _InputPageState createState() => _InputPageState();
}

class _InputPageState extends State<InputPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            const SizedBox(
              height: 40,
            ),
            const Text('Choose an option',
              style:  TextStyle(
                fontSize: 40,
                color: Colors.white,
                fontWeight: FontWeight.bold,
                letterSpacing: 0.7,
                fontFamily: 'Libre Baskerville',
                //fontFamily:
              ),
            ),
            const SizedBox(
              height: 30,
            ),
            GestureDetector(
                onTap: () {
                  Navigator.push(context,
                      MaterialPageRoute(builder: (context) => TechNews()));
                },
              child: Container(
                padding: EdgeInsets.all(15.0),
                width: 250.0,
                height: 250.0,
                decoration: const BoxDecoration(
                    image: DecorationImage(
                        image: NetworkImage(
                            "https://www.inclusivecompanies.co.uk/wp-content/uploads/2020/05/Tech.jpg"
                        ),
                        fit: BoxFit.cover
                    ),
                    borderRadius: BorderRadius.all(Radius.circular(20)),

                ),
                child: const Text(
                  'Tech News',
                  textAlign: TextAlign.right,
                  style:  TextStyle(
                    fontSize: 40,
                    color: Colors.white,
                    fontWeight: FontWeight.bold,
                    fontFamily: 'Abril Fatface',
                  ),
                ),


              ),
            ),
            const SizedBox(
              height: 80,
            ),
            GestureDetector(
              onTap: () {
                Navigator.push(context,
                    MaterialPageRoute(builder: (context) => Scholarships()));
              },
              child: Container(
                width: 250.0,
                height: 250.0,
                padding: EdgeInsets.all(15.0),
                decoration: const BoxDecoration(
                  image: DecorationImage(
                      image: NetworkImage(
                          "https://thumbor.forbes.com/thumbor/960x0/https%3A%2F%2Fspecials-images.forbesimg.com%2Fimageserve%2F1124469358%2FBlack-hat-and-yellow-tassel-of-graduates-placed-on-a-wooden-table%2F960x0.jpg%3Ffit%3Dscale"
                      ),
                      fit: BoxFit.cover
                  ),
                    borderRadius: BorderRadius.all(Radius.circular(10)),
                ),
                child: const Text(
                  'Scholarships',
                  textAlign: TextAlign.right,
                  style:  TextStyle(
                    fontSize: 40,
                    color: Colors.black,
                    fontWeight: FontWeight.bold,
                    fontFamily: 'Abril Fatface',
                    //fontFamily:
                  ),
                ),
              ),
            ),

         ],
        ),
      ),
    );
  }
}
