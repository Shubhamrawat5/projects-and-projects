import 'package:flutter/material.dart';
import 'package:url_launcher/url_launcher.dart';
class Scholarships extends StatelessWidget {
  const Scholarships({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        //padding: const EdgeInsets.all(20.0),
        child: Column(
          children: [
            const Text('Scholarships',
              style:  TextStyle(
                fontSize: 50,
                color: Colors.white,
                fontWeight: FontWeight.bold,
                fontFamily: 'Abril Fatface',
                //fontFamily:
              ),
            ),
            const SizedBox(
              height: 40,
            ),
            Expanded(
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: ListView(
                  children: [
                    ListTile(
                      title: Text(
                        'Generation Google Scholarship',
                        style:  TextStyle(
                          fontSize: 25,
                          color: Colors.white,
                          fontWeight: FontWeight.bold,
                          fontFamily: 'Libre Baskerville',
                        ),
                      ),
                      subtitle: Text(
                        'Generation Google Scholarship 2021-2022 is offered to young women in the field of computer science. This scholarship was established with the aim to empower motivated and highly talented women around the globe. The scholarship will be granted on the basis of academic performance, diversity, leadership qualities, and equity. The scholarship amount is meant to be spent on books, academic-related expenses, and tuition fees.',
                        style: TextStyle(
                            fontFamily: 'Slabo 27px'
                        ),
                      ),
                      onTap: () async {
                        const url = 'https://edu.google.com/intl/ALL_no/scholarships/the-generation-google-scholarship/';
                        if (await canLaunch(url)) {
                          await launch(url);
                        } else {
                          throw 'Could not launch $url';
                        }
                      },
                    ),
                    const Divider(
                      height: 20,
                      thickness: 5,
                    ),
                    ListTile(
                      title: Text(
                        'Adobe India WIT Scholarship',
                        style:  TextStyle(
                          fontSize: 25,
                          color: Colors.white,
                          fontWeight: FontWeight.bold,
                          fontFamily: 'Libre Baskerville',
                        ),
                      ),
                      subtitle: Text(
                        'Adobe India Women-in-Technology Scholarship 2021 is open for Indian females enrolled in a formal technology program in computer science, computer engineering, or a closely related technical field. The scholarship offered by Adobe Research aims to recognize outstanding female students in the field of technology. The scholarship focuses on creating gender equality in the science and engineering domain by encouraging women to excel in computing and technology. The selected fellows will receive variable awards.',
                        style: TextStyle(
                            fontFamily: 'Slabo 27px'
                        ),
                      ),
                      onTap: () async {
                        const url = 'https://research.adobe.com/adobe-india-women-in-technology-scholarship/';
                        if (await canLaunch(url)) {
                          await launch(url);
                        } else {
                          throw 'Could not launch $url';
                        }
                      },
                    ),
                    const Divider(
                      height: 20,
                      thickness: 5,
                    ),
                    ListTile(
                      title: Text(
                        'Goldman Sachs WeTech Program',
                        style:  TextStyle(
                          fontSize: 25,
                          color: Colors.white,
                          fontWeight: FontWeight.bold,
                          fontFamily: 'Libre Baskerville',
                        ),
                      ),
                      subtitle: Text(
                        'WeTech, or Women Enhancing Technology, is a consortium of dedicated partners that is led by the Institute of International Education (IIE), to design and support a series of innovative activities to provide training, build networks and offer professional opportunities. WeTech helps women and girls enter and succeed in technology careers, with the goal of enhancing women’s talent and skills needed to fuel technological and economic growth. Launched at the Clinton Global Initiative Annual Meeting in 2013, WeTech has engaged 27 companies, 200 mentors, 50 schools and universities, and 10,000 participants in 21 countries to date',
                        style: TextStyle(
                            fontFamily: 'Slabo 27px'
                        ),
                      ),
                      onTap: () async {
                        const url = 'https://www.iie.org/Programs/WeTech/STEM-Scholarships-for-Women/Goldman-Sachs-Scholarship';
                        if (await canLaunch(url)) {
                          await launch(url);
                        } else {
                          throw 'Could not launch $url';
                        }
                      },
                    ),
                    const Divider(
                      height: 20,
                      thickness: 5,
                    ),
                    ListTile(
                      title: Text(
                        'Grace Hopper Celebration',
                        style:  TextStyle(
                          fontSize: 25,
                          color: Colors.white,
                          fontWeight: FontWeight.bold,
                          fontFamily: 'Libre Baskerville',
                        ),
                      ),
                      subtitle: Text(
                        'Grace Hopper Celebration India (GHCI) invites application for Grace Hopper Celebration India (GHCI) Student Scholarships 2020 from women applicants of undergraduate, masters and PhD program from computing, engineering, and IT backgrounds. The objective of this program is to gain inspiration and get guidance for a career in technology. The selected applicants will receive full conference registration fee and meals, travel fare up to INR 3,000 and accommodation.',
                        style: TextStyle(
                            fontFamily: 'Slabo 27px'
                        ),
                      ),
                      onTap: () async {
                        const url = 'https://ghc.anitab.org/attend/scholarships/';
                        if (await canLaunch(url)) {
                          await launch(url);
                        } else {
                          throw 'Could not launch $url';
                        }
                      },
                    ),
                    const Divider(
                      height: 20,
                      thickness: 5,
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
