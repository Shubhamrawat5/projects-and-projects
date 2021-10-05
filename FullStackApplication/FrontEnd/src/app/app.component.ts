import { Component, OnInit } from '@angular/core';
import { Customer } from './customer';
import { CustomerService } from './customer.service';
import { HttpErrorResponse } from '@angular/common/http';
import { NgForm } from '@angular/forms';
import {NgbNav,NgbNavOutlet} from '@ng-bootstrap/ng-bootstrap'
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements OnInit{

  title = 'tryagian';
  constructor() {}
  ngOnInit(){
  //  this.getCustomers();
  }

}
