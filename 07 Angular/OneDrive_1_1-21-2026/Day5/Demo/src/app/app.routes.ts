import { Routes } from '@angular/router';
import { Students } from './components/Day5/students/students';
import { StudentDetails } from './components/Day5/student-details/student-details';
import { About } from './components/Day5/about/about';
import { Profile } from './components/Day5/profile/profile';
import { Error } from './components/Day5/error/error';

export const routes: Routes = [
  {path: '', component: Students},
  {path: 'students', component: Students},
  {path: 'students/:id', component: StudentDetails},
  {path: 'about', component: About},
  {path: 'profile', component: Profile},
  {path: '**', component: Error},
];
