import { Component, OnInit } from '@angular/core';
import { Customer } from '../customer';
import { CustomerService } from '../customer.service';
import { HttpErrorResponse } from '@angular/common/http';
import { NgForm } from '@angular/forms';
@Component({
  selector: 'app-view-one',
  templateUrl: './view-one.component.html',
  styleUrls: ['./view-one.component.css']
})
export class ViewOneComponent implements OnInit {
  public customer!: Customer;
  public view!:string;
  constructor(private customerService:CustomerService) { }

  ngOnInit(): void {
  //  this.getCustomer(1);
  }
  public getCustomer(da:any):void{
    this.customerService.getEmployee(da.id).subscribe(
      (response:Customer)=>{
        this.customer=response;
        console.log(this.customer);
        this.view="yes";
      },
      (error:HttpErrorResponse)=>{
        alert(error.message);
      }
    );
  }
}
