<div dir="rtl" lang="he">

# משחק מלחמה - שלב א

במטלה זו עליכם לתכנן משחק מלחמה לשני שחקנים על לוח מלבני.

לכל שחקן יש מספר חיילים מסוגים שונים, לכל סוג חייל יש יכולות שונות המפורטות בהמשך.
כל שחקן בתורו יכול להזיז שחקן אחד למקום אחד לבחירתו, בהתאם ליכולות התנועה של החייל.
אותו חייל שזז, גם יורה או פועל באותו תור בהתאם ליכולת הפעולה שלו.
כל חייל מתחיל עם מספר מסויים של נקודות-בריאות.
כל יריה מורידה לנפגע מספר מסויים של נקודות-בריאות.
חייל שמספר נקודות-הבריאות שלו מגיע לאפס - יוצא מהלוח.
שחקן שכל החיילים שלו יצאו מהלוח - מפסיד.


## רשימת החיילים והיכולות

* FootSoldier - רגלי - יכול ללכת 3 משבצות לכל כיוון. יורה על החייל של האויב שנמצא הכי קרוב אליו (אם יש כמה - הוא יורה על אחד מהם שרירותית).
* FootCommander - כמו רגלי, אבל כשהוא זז, לא רק הוא יורה אלא כל החיילים הרגלים של אותו שחקן יורים.
* Sniper - צלף - יכול ללכת משבצת אחת לכל כיוון. יורה על החייל החזק ביותר של האויב - זה שיש לו הכי הרבה נקודות בריאות (אם יש כמה - הוא בוחר אחד מהם שרירותית).
* SniperCommander - כמו צלף, אבל כשהוא זז, לא רק הוא יורה אלא כל הצלפים של אותו שחקן יורים.
* Paramedic - חובש - יכול ללכת שתי משבצות לכל כיוון. לא יורה בכלל, אלא רק מרפא את כל החיילים של אותו שחקן שנמצאים במשבצת לידו.
* ParamedicCommander - כמו חובש, אבל כשהוא זז, כל החובשים של אותו שחקן מרפאים את החיילים שנמצאים לידם.

## הגשה

כמו תמיד בשלב א יש לכתוב בדיקות-יחידה מקיפות. הפקודות הבאות צריכות לרוץ בלי שגיאות:

<div dir='ltr'>

    make demo && ./demo
	make test && ./test

</div>

במטלה זו, מפאת קוצר הזמן, אין צורך לבדוק מקרי-קצה, אלא רק לבדוק את הדרישות הבסיסיות.


## דגשים

* לפני שמתחילים לתכנת, יש לתכנן את מבנה הקוד, המחלקות והירושות. יש להגיש בגיטהאב, יחד עם הקוד, מסמך תיכנון מפורט.
* יש לתכנן את הקוד באופן שיהיה קל להרחבה ולשינוי בעתיד, למשל אם נרצה להוסיף סוגים שונים של חיילים או לשנות את חוקי המשחק.


## מקורות

* ההשראה למטלה היא ממטלה של גיל לוי בקורס "תיכנות מתקדם" שנת ה'תשע"ז.

</div>