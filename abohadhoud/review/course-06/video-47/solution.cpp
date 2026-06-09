vector <int> num{ 1,2,3,4,5 };
cout << "Initial Vector : ";
// & عم const
// اهرييغت ىلع ةردقلا مدعو ريغتملا ةميق تيبثت
for (const int& i : num)
{
cout << i << " ";
// Print 1 2 3 4 5
}
cout << "\n\n Updated Vector : ";
// طقف Reference & ةراشإ
// ريغتملا ةميق رييغت عيطتست
for ( int& i : num)
{
i = 20;
cout << i << " ";
}
// Print 20 20 20 20 20
// ريغتملا ةميق رييغت عيطتست
num[1] = 40;
num.at(2) = 80;
num.at(4) = 90;
cout << "\n\n Updated Vector : ";
// & عم const
// اهرييغت ىلع ةردقلا مدعو ريغتملا ةميق تيبثت
for (const int& i : num)
{
cout << i << " ";
}
// Print 20 40 80 20 90