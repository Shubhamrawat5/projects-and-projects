import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HttpClientModule } from '@angular/common/http';
import { CustomerService } from './customer.service';
import { FormsModule } from '@angular/forms';
import { ViewAllComponent } from './view-all/view-all.component';
import { ViewOneComponent } from './view-one/view-one.component';
import { AddOneComponent } from './add-one/add-one.component';
import { UpdateOneComponent } from './update-one/update-one.component';
import { DeleteOneComponent } from './delete-one/delete-one.component';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
@NgModule({
  declarations: [
    AppComponent,
    ViewAllComponent,
    ViewOneComponent,
    AddOneComponent,
    UpdateOneComponent,
    DeleteOneComponent,
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    HttpClientModule,
    NgbModule
  ],
  providers: [CustomerService],
  bootstrap: [AppComponent]
})
export class AppModule { }
