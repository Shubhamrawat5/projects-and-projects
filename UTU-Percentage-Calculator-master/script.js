let buttonCal = document.getElementById("calcu");
buttonCal.addEventListener("click", function () {
  let sem1 = Number(document.getElementById("FirstSemMarks").value);
  let sem2 = Number(document.getElementById("SecondSemMarks").value);
  let sem3 = Number(document.getElementById("ThirdSemMarks").value);
  let sem4 = Number(document.getElementById("ForthSemMarks").value);
  let sem5 = Number(document.getElementById("FifthSemMarks").value);
  let sem6 = Number(document.getElementById("SixthSemMarks").value);
  let sem7 = Number(document.getElementById("SeventhSemMarks").value);
  let sem8 = Number(document.getElementById("EightthSemMarks").value);

  let totalsem1 = Number(document.getElementById("FirstSemTotalMarks").value);
  let totalsem2 = Number(document.getElementById("SecondSemTotalMarks").value);
  let totalsem3 = Number(document.getElementById("ThirdSemTotalMarks").value);
  let totalsem4 = Number(document.getElementById("ForthSemTotalMarks").value);
  let totalsem5 = Number(document.getElementById("FifthSemTotalMarks").value);
  let totalsem6 = Number(document.getElementById("SixthSemTotalMarks").value);
  let totalsem7 = Number(document.getElementById("SeventhSemTotalMarks").value);
  let totalsem8 = Number(document.getElementById("EightthSemTotalMarks").value);

  // For 1st year
  let semester1 = (sem1 / totalsem1) * 100;
  let semester2 = (sem2 / totalsem2) * 100;
  let firstYear = (semester1 + semester2) / 2; //First year  (100%)
  let aggrfirstYear = firstYear * 0.25; //First year (25%)

  // For 2nd year
  let semester3 = (sem3 / totalsem3) * 100;
  let semester4 = (sem4 / totalsem4) * 100;
  let SecondYear = (semester3 + semester4) / 2; // SecondYear  (100%)
  let aggrSecondYear = SecondYear * 0.5; // SecondYear  (25%)

  // For 3rd year
  let semester5 = (sem5 / totalsem5) * 100;
  let semester6 = (sem6 / totalsem6) * 100;
  let ThirdYear = (semester5 + semester6) / 2; //ThirdYear  (100%)
  let aggrThirdYear = ThirdYear * 0.75; //ThirdYear  (25%)

  // For 4st year
  let semester7 = (sem7 / totalsem7) * 100;
  let semester8 = (sem8 / totalsem8) * 100;
  let forthYear = (semester7 + semester8) / 2; // forthYear  (100%)
  let aggrforthYear = forthYear * 1; // forthYear  (25%)

  //Total (denominator) according to UTU
  let AggrTotalFirstYear = ((totalsem1 + totalsem2) / 2) * 0.25;

  let AggrTotalSecondYear = ((totalsem3 + totalsem4) / 2) * 0.5;
  let AggrTotalThirdYear = ((totalsem5 + totalsem6) / 2) * 0.75;
  let AggrTotalForthYear = ((totalsem7 + totalsem8) / 2) * 1;

  let FinalPercentageObtained =
    ((aggrfirstYear + aggrSecondYear + aggrThirdYear + aggrforthYear) /
      (AggrTotalFirstYear +
        AggrTotalSecondYear +
        AggrTotalThirdYear +
        AggrTotalForthYear)) *
    1000;

  console.log(FinalPercentageObtained);

  //Result for Each SEMESTER
  document.querySelector("#Result-sem1").textContent = semester1.toFixed(2);
  document.querySelector("#Result-sem2").textContent = semester2.toFixed(2);
  document.querySelector("#Result-sem3").textContent = semester3.toFixed(2);
  document.querySelector("#Result-sem4").textContent = semester4.toFixed(2);
  document.querySelector("#Result-sem5").textContent = semester5.toFixed(2);
  document.querySelector("#Result-sem6").textContent = semester6.toFixed(2);
  document.querySelector("#Result-sem7").textContent = semester7.toFixed(2);
  document.querySelector("#Result-sem8").textContent = semester8.toFixed(2);

  //Result for Each Year
  document.querySelector("#Result-year1").textContent = firstYear.toFixed(2);
  document.querySelector("#Result-year2").textContent = SecondYear.toFixed(2);
  document.querySelector("#Result-year3").textContent = ThirdYear.toFixed(2);
  document.querySelector("#Result-year4").textContent = forthYear.toFixed(2);

  //Result for Each Year(Aggerate)
  document.querySelector("#Result-year1Aggr").textContent =
    aggrfirstYear.toFixed(2);
  document.querySelector("#Result-year2Aggr").textContent =
    aggrSecondYear.toFixed(2);
  document.querySelector("#Result-year3Aggr").textContent =
    aggrThirdYear.toFixed(2);
  document.querySelector("#Result-year4Aggr").textContent =
    aggrforthYear.toFixed(2);

  document.querySelector("#aggrfinalResult").textContent =
    FinalPercentageObtained.toFixed(2);
});
