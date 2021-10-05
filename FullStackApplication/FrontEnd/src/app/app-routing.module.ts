import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { AddOneComponent } from './add-one/add-one.component';
import { DeleteOneComponent } from './delete-one/delete-one.component';
import { UpdateOneComponent } from './update-one/update-one.component';
import { ViewAllComponent } from './view-all/view-all.component';
import { ViewOneComponent } from './view-one/view-one.component';

const routes: Routes = [
  {
    path: "viewOne",
    component: ViewOneComponent
  },
  {
    path: "viewAll",
    component: ViewAllComponent
  },
  {
    path: "addOne",
    component: AddOneComponent
  },
  {
    path: "updateOne",
    component: UpdateOneComponent
  },
  {
    path: "deleteOne",
    component: DeleteOneComponent
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
