import { Component, OnInit } from '@angular/core';
import { Customer } from '../customer';
import { CustomerService } from '../customer.service';
import { HttpErrorResponse } from '@angular/common/http';
import { NgForm } from '@angular/forms';
@Component({
  selector: 'app-view-all',
  templateUrl: './view-all.component.html',
  styleUrls: ['./view-all.component.css']
})
export class ViewAllComponent implements OnInit {
  public customers: Customer[] = [];
  public c:number=0;
  constructor(private customerService:CustomerService) { }

  ngOnInit(): void {
    this.getCustomers();
  }
  public getCustomers():void{
    this.customerService.getEmployees().subscribe(
      (response:Customer[])=>{
        this.customers=response;
        console.log(this.customers);
      },
      (error:HttpErrorResponse)=>{
        alert(error.message);
      }
    );
  }
  increase(){
    this.c = this.c+1;
  }
}
