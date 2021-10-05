import { Component, OnInit } from '@angular/core';
import { Customer } from '../customer';
import { CustomerService } from '../customer.service';
import { HttpErrorResponse } from '@angular/common/http';
import { NgForm } from '@angular/forms';
@Component({
  selector: 'app-update-one',
  templateUrl: './update-one.component.html',
  styleUrls: ['./update-one.component.css']
})
export class UpdateOneComponent implements OnInit {
  public customer!: Customer;
  public view!:string;
  public viewForSuccess!:string;
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

  public onAddCustomer(addForm: NgForm): void {
    addForm.value.id=this.customer.id;
    this.customerService.addEmployee(addForm.value).subscribe(
      (response: Customer) => {
        console.log(response);
        this.viewForSuccess="yes";
      },
      (error: HttpErrorResponse) => {
        alert(error.message);
        addForm.reset();
      }
    );
  }

}
